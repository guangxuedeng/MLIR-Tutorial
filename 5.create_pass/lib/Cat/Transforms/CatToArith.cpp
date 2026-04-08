#include "Cat/Transforms/Passes.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/Transforms/DialectConversion.h"
#include "Cat/IR/CatDialect.h"
#include "Cat/IR/CatOps.h"

namespace mlir {
namespace cat {
    #define GEN_PASS_DEF_CONVERTCATTOARITHPASS
    #include "Cat/Transforms/Passes.h.inc"
}
}

using namespace mlir;
using namespace mlir::cat;


struct LowerCatAdd : public OpRewritePattern<cat::AddOp> {
    using OpRewritePattern<cat::AddOp>::OpRewritePattern;

    LogicalResult matchAndRewrite(cat::AddOp addOp, PatternRewriter &rewriter) const override {
        rewriter.replaceOpWithNewOp<arith::AddIOp>(
            addOp,
            addOp.getLhs(),
            addOp.getRhs()
        );
        return llvm::success();
    } 
};


struct CatToArithPass :
        public ::mlir::cat::impl::ConvertCatToArithPassBase<CatToArithPass> {
    void runOnOperation() override;
};

void CatToArithPass::runOnOperation() {
    ModuleOp module = getOperation();

    ConversionTarget target(getContext());
    target.addLegalDialect<arith::ArithDialect>();
    target.addIllegalDialect<cat::CatDialect>();
    
    RewritePatternSet patterns(&getContext());
    patterns.add<LowerCatAdd>(&getContext());
    
    if(llvm::failed(applyPartialConversion(module, target, std::move(patterns)))) {
        signalPassFailure();
    }
}


std::unique_ptr<Pass> mlir::cat::createCatLowerToArithPass() {
  return std::make_unique<CatToArithPass>();
}