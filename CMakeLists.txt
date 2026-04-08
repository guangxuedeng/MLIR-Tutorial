cmake_minimum_required(VERSION 3.13.4)

project(MLIR-Tutorial VERSION 0.0.0)

# 生成 compile_commands.json 记录所有源文件的编译命令用于工具分析
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
# 强制使用CMAKE_CXX_STANDARD中设置的版本
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# 查找MLIRConfig.cmake文件
find_package(MLIR REQUIRED CONFIG)
# 将模块目录添加到CMake 的模块查找路径中
# MLIR_CMAKE_DIR和LLVM_CMAKE_DIR来自MLIRConfig.cmake和LLVMConfig.cmake中定义的变量
list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")

# include将指定cmake文件中的内容复制到当前文件
# 引入TableGen.cmake文件
include(TableGen)
include(AddLLVM)
include(AddMLIR)
include(HandleLLVMOptions)

# 添加头文件搜索路径
include_directories(${LLVM_INCLUDE_DIRS} ${MLIR_INCLUDE_DIRS})

add_executable(mlir-toy main.cpp)
target_link_libraries(
  mlir-toy 
  MLIRIR
  MLIRParser
  MLIRFuncDialect
  MLIRArithDialect
)


add_subdirectory(1.read_mlir)
add_subdirectory(2.create_mlir)
add_subdirectory(3.create_dialect)
add_subdirectory(4.create_ops)
add_subdirectory(5.create_pass)