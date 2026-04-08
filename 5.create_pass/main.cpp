#include "mlir/IR/MLIRContext.h"
#include "Cat/IR/CatDialect.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "Cat/IR/CatOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/IR/Verifier.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Pass/PassManager.h"
#include "Cat/Transforms/Passes.h"

mlir::ModuleOp getMLIR(mlir::MLIRContext &ctx) {
    ctx.getOrLoadDialect<mlir::cat::CatDialect>();
    ctx.getOrLoadDialect<mlir::arith::ArithDialect>();
    ctx.getOrLoadDialect<mlir::func::FuncDialect>();

    mlir::OpBuilder builder(&ctx);
    auto module = builder.create<mlir::ModuleOp>(builder.getUnknownLoc(), "test");
    builder.setInsertionPointToEnd(module.getBody());
    
    auto funcType = mlir::FunctionType::get(&ctx, {}, {});
    auto func = builder.create<mlir::func::FuncOp>(builder.getUnknownLoc(), "test_pass", funcType);

    auto block = func.addEntryBlock();
    builder.setInsertionPointToStart(block);


    auto i32 = mlir::IntegerType::get(&ctx, 32);
    mlir::Value const_10 = builder.create<mlir::arith::ConstantOp>(builder.getUnknownLoc(), i32, builder.getI32IntegerAttr(0));
    mlir::Value const_20 = builder.create<mlir::arith::ConstantOp>(builder.getUnknownLoc(), i32, builder.getI32IntegerAttr(20));
    
    auto add1 = builder.create<mlir::cat::AddOp>(builder.getUnknownLoc(), i32, const_10, const_20);
    
    auto add2 = builder.create<mlir::cat::AddOp>(builder.getUnknownLoc(), i32, add1, const_20);
    
    
    builder.create<mlir::func::ReturnOp>(builder.getUnknownLoc());
    module->print(llvm::outs());
    return module;
}

int main(){
    mlir::MLIRContext ctx;
    auto module = getMLIR(ctx);

    // 运行第一个 Pass
    mlir::PassManager pm1(&ctx);
    pm1.addNestedPass<mlir::func::FuncOp>(mlir::cat::createCatAddCanonicalizerPass());
    pm1.run(module);
    llvm::outs() << "\n=== 规范化后 ===\n";
    module->print(llvm::outs());

    // 运行第二个 Pass
    mlir::PassManager pm2(&ctx);
    pm2.addPass(mlir::cat::createCatLowerToArithPass());
    pm2.run(module);
    llvm::outs() << "\n=== Lowering 后 ===\n";
    module->print(llvm::outs());

    return 0;
}