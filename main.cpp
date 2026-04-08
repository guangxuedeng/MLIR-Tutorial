#include "mlir/IR/Builders.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
using namespace mlir;

int main(int argc, char **argv) {
    MLIRContext ctx;
    ctx.loadDialect<func::FuncDialect>();
    
    OpBuilder builder(&ctx);
}
