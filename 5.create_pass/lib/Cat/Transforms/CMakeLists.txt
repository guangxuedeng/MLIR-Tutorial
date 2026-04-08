add_mlir_dialect_library(MLIRCatTransforms_5
    CatCanonicalizer.cpp
    CatToArith.cpp
    DEPENDS
    MLIRCatPassIncGen_5
)