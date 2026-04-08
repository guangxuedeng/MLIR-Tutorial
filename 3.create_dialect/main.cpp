#include "mlir/IR/MLIRContext.h"
#include "Cat/IR/CatDialect.h"

int main() {
    mlir::MLIRContext ctx;
    ctx.loadDialect<mlir::cat::CatDialect>();
}