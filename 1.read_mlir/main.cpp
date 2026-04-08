#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/MLIRContext.h"

#include "mlir/Parser/Parser.h"
#include "llvm/Support/raw_ostream.h"
int main(int argc, char ** argv) {
    mlir::MLIRContext ctx;
    ctx.loadDialect<mlir::func::FuncDialect, mlir::arith::ArithDialect>();
    
    auto src = mlir::parseSourceFile<mlir::ModuleOp>(argv[1], &ctx);
    src->print(llvm::outs());
    src->dump();
    return 0;
}