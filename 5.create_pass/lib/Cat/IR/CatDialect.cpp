#include "Cat/IR/CatDialect.h"
#include "Cat/IR/CatOps.h"


using namespace mlir;
using namespace mlir::cat;

#include "Cat/IR/CatDialect.cpp.inc"

void cat::CatDialect::initialize() {
    addOperations<
        #define GET_OP_LIST
        #include "Cat/IR/CatOps.cpp.inc"
    >();
}