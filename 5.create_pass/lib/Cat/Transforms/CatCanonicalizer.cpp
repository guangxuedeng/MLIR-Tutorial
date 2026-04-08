#include "Cat/Transforms/Passes.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "Cat/IR/CatOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"

namespace mlir {
namespace cat {
    #define GEN_PASS_DEF_CATCANONICALIZERPASS
    #include "Cat/Transforms/Passes.h.inc"
}
}

using namespace mlir;
using namespace mlir::cat;

namespace {
    struct CatAddCanonicalizer : 
            public cat::impl::CatCanonicalizerPassBase<CatAddCanonicalizer>{
        void runOnOperation() override {
            func::FuncOp func = getOperation();

            func->walk([&](cat::AddOp addOp){
                Value lhs = addOp.getLhs();
                Value rhs = addOp.getRhs();

                auto isConstZero = [](Value v) {
                    auto constOp = v.getDefiningOp<arith::ConstantOp>();
                    if(!constOp)   
                        return false;
                    if(auto intAttr = llvm::dyn_cast<IntegerAttr>(constOp.getValue())) {
                        return intAttr.getInt() == 0;
                    }
                    return false;
                };
                
                if(isConstZero(lhs)) {
                    OpBuilder builder(addOp);
                    addOp.replaceAllUsesWith(rhs);
                    addOp.erase();
                    return;
                }
                if(isConstZero(rhs)) {
                    OpBuilder builder(addOp);
                    addOp.replaceAllUsesWith(lhs);
                    addOp.erase();
                    return;
                }
            });
        }
    };
}

std::unique_ptr<Pass> mlir::cat::createCatAddCanonicalizerPass() {
    return std::make_unique<CatAddCanonicalizer>();
}