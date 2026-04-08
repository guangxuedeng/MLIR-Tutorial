#include "Cat/IR/CatOps.h"

#define GET_OP_CLASSES
#include "Cat/IR/CatOps.cpp.inc"


::llvm::LogicalResult mlir::cat::AddOp::verify() {
    // 校验 add 的输入结果和输出结果必须相同
    Type inputType = getLhs().getType();
    Type resultType = getResult().getType();
    if (inputType != resultType) {
        emitOpError() << "输出类型必须和输入类型完全相同";
        return llvm::failure();
    }
    return llvm::success();
}