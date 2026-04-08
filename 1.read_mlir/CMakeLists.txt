add_executable(Toy-1 "main.cpp")


target_link_libraries(
  Toy-1
  MLIRIR
  MLIRParser
  MLIRFuncDialect
  MLIRArithDialect
)