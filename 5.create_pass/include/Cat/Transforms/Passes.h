#ifndef MLIR_DIALECT_CAT_TRANSFORMS_PASSES_H
#define MLIR_DIALECT_CAT_TRANSFORMS_PASSES_H

#include "mlir/Pass/Pass.h"

namespace mlir {

namespace cat {
    #define GEN_PASS_DECL 
    #include "Cat/Transforms/Passes.h.inc"


    std::unique_ptr<Pass> createCatAddCanonicalizerPass();

    std::unique_ptr<Pass> createCatLowerToArithPass();
    #define GEN_PASS_REGISTRATION
    #include "Cat/Transforms/Passes.h.inc"
}

}


#endif // MLIR_DIALECT_CAT_TRANSFORMS_PASSES_H