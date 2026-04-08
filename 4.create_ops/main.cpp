#include "mlir/IR/MLIRContext.h"
#include "Cat/IR/CatDialect.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "Cat/IR/CatOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/IR/Verifier.h"

int main(){
    mlir::MLIRContext ctx;
    ctx.getOrLoadDialect<mlir::cat::CatDialect>();
    ctx.getOrLoadDialect<mlir::arith::ArithDialect>();

    mlir::OpBuilder builder(&ctx);
    auto module = builder.create<mlir::ModuleOp>(builder.getUnknownLoc(), "test");
    builder.setInsertionPointToEnd(module.getBody());
    
    auto i32 = mlir::IntegerType::get(&ctx, 32);
    mlir::Value const_10 = builder.create<mlir::arith::ConstantOp>(builder.getUnknownLoc(), i32, builder.getI32IntegerAttr(10));
    mlir::Value const_20 = builder.create<mlir::arith::ConstantOp>(builder.getUnknownLoc(), i32, builder.getI32IntegerAttr(20));
    
    auto i64 = mlir::IntegerType::get(&ctx, 64);
    
    builder.create<mlir::cat::AddOp>(builder.getUnknownLoc(), i64, const_10, const_20);

    module->print(llvm::outs());
    if (::mlir::failed(::mlir::verify(module))) {
    llvm::errs() << "module verification failed\n";
    return 1;
    }
    return 0;
}