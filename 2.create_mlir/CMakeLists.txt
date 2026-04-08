add_executable(Toy-2 "main.cpp")


target_link_libraries(
  Toy-2
  MLIRIR
  MLIRParser
  MLIRFuncDialect
  MLIRArithDialect
)