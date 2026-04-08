#ifndef MLIR_DIALECT_CAT_IR_CATOPS_TD
#define MLIR_DIALECT_CAT_IR_CATOPS_TD

include "Cat/IR/CatDialect.td"

class Cat_Op<string mnemonic, list<Trait> traits = []> :
    Op<Cat_Dialect, mnemonic, traits>;


def AddOp : Cat_Op<"add", []> {
    let summary = "add operation";
    let arguments = (ins
        AnyInteger:$lhs,
        AnyInteger:$rhs
    );
    let results = (outs
        AnyInteger:$result
    );
    // 生成校验函数
    let hasVerifier = 1;
}

#endif //MLIR_DIALECT_CAT_IR_CATOPS_TD