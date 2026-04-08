# MLIR 封装的高层 CMake 宏，一键创建符合 MLIR 规范的方言库，
# 省略手动配置依赖、头文件、编译选项的繁琐步骤
add_mlir_dialect_library(MLIRCatDialect_4
    CatDialect.cpp
    CatOps.cpp
    DEPENDS
    MLIRCatIncGen_4

    LINK_LIBS PUBLIC
    MLIRIR
    MLIRParser
    MLIRArithDialect
)