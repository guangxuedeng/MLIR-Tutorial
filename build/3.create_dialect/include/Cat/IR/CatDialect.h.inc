/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: CatDialect.td                                                        *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace cat {

class CatDialect : public ::mlir::Dialect {
  explicit CatDialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~CatDialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("cat");
  }
};
} // namespace cat
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::cat::CatDialect)
