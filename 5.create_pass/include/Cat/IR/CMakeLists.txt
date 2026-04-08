# 指定 TableGen 工具的输入文件
# LLVM_TARGET_DEFINITIONS 
set(LLVM_TARGET_DEFINITIONS CatDialect.td)
mlir_tablegen(CatDialect.h.inc -gen-dialect-decls -dialect=cat)
mlir_tablegen(CatDialect.cpp.inc -gen-dialect-defs -dialect=cat)

set(LLVM_TARGET_DEFINITIONS CatOps.td)
mlir_tablegen(CatOps.h.inc -gen-op-decls)
mlir_tablegen(CatOps.cpp.inc -gen-op-defs)

# 封装 TableGen 代码生成的全流程，并对外暴露一个可依赖的构建目标
add_public_tablegen_target(MLIRCatIncGen_5)