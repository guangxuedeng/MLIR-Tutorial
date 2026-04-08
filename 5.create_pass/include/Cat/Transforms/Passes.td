#ifndef MLIR_DIALECT_CAT_TRANSFORMS_PASSES_TD
#define MLIR_DIALECT_CAT_TRANSFORMS_PASSES_TD

include "mlir/Pass/PassBase.td"

def CatCanonicalizerPass : Pass<"canonicalizer-cat-add", "func::FuncOp"> {
    let summary = "Canonicalize CatAddOp (x+0 -> x)";
    // 定义了constructor就需要自己在头文件中定义并在源文件中实现createCatAddCanonicalizerPass
    let constructor = "createCatAddCanonicalizerPass()";
}

// 不写Pass的第二个参数默认挂载到ModuleOp
def ConvertCatToArithPass : Pass<"convert-cat-to-arith", "mlir::ModuleOp"> {
    let summary = "Lower Cat dialect to Arith";
    let dependentDialects = [
        "arith::ArithDialect"
    ];
    let constructor = "createCatLowerToArithPass()";
} 

#endif //MLIR_DIALECT_CAT_TRANSFORMS_PASSES_TD