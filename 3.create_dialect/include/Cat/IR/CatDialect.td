#ifndef MLIR_DIALECT_CAT_IR_CATDIALECT_TD
#define MLIR_DIALECT_CAT_IR_CATDIALECT_TD

include "mlir/IR/OpBase.td"

def Cat_Dialect : Dialect {
  let name = "cat";
  let cppNamespace = "::mlir::cat";
  let summary = "Cat Dialect";

  // 是否生成默认的析构函数
  // 本实例为演示方言的注册和销毁过程，禁用默认的析构函数
  let hasNonDefaultDestructor = 1;

}
#endif // MLIR_DIALECT_CAT_IR_CATDIALECT_TD