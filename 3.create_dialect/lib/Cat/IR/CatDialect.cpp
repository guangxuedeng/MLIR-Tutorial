#include "Cat/IR/CatDialect.h"


using namespace mlir;
using namespace mlir::cat;

#include "Cat/IR/CatDialect.cpp.inc"

void cat::CatDialect::initialize() {
    llvm::outs() << getDialectNamespace() << "初始化完成" << "\n";
}

cat::CatDialect::~CatDialect() {
    // 可选清理代码
    llvm::outs() << getDialectNamespace() << "析沟函数执行" << "\n";
}