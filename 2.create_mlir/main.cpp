#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/ValueRange.h"
#include "llvm/Support/raw_ostream.h"
using namespace mlir;

int main(int argc, char ** argv) {
    mlir::MLIRContext ctx;
    ctx.loadDialect<func::FuncDialect, arith::ArithDialect>();
    
    OpBuilder builder(&ctx);
    // 一个MLIR只有一个顶级ModuleOp并绑定到一个MLIRContext
    auto mod = builder.create<ModuleOp>(builder.getUnknownLoc());
    
    builder.setInsertionPointToEnd(mod.getBody());
    
    auto i32 = builder.getI32Type();
    // 入参类型和返回值类型
    auto funcType = builder.getFunctionType({i32, i32}, i32);
    auto func = builder.create<func::FuncOp>(builder.getUnknownLoc(), "my_funct", funcType);
    
    // 为func添加一个block，该Block会自动匹配func的入参和出参
    auto entry = func.addEntryBlock();
    // 获取Block即func的入参
    auto args = entry->getArguments();
    
    builder.setInsertionPointToEnd(entry);
    
    auto addi = builder.create<arith::AddIOp>(builder.getUnknownLoc(), args[0], args[1]);
    
    builder.create<func::ReturnOp>(builder.getUnknownLoc(), ValueRange{addi});

    mod.print(llvm::outs());
    return 0;
    
}