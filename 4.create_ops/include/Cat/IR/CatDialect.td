#ifndef MLIR_DIALECT_CAT_IR_CATDIALECT_TD
#define MLIR_DIALECT_CAT_IR_CATDIALECT_TD

include "mlir/IR/OpBase.td"

def Cat_Dialect : Dialect {
  let name = "cat";
  let cppNamespace = "::mlir::cat";
  let summary = "Cat Dialect";
}
#endif // MLIR_DIALECT_CAT_IR_CATDIALECT_TD