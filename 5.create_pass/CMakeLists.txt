include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

add_subdirectory(include)
add_subdirectory(lib)

add_executable(Toy-5 "main.cpp")

target_link_libraries(Toy-5 
    MLIRCatDialect_5
    MLIRCatTransforms_5

    MLIRIR
    MLIRParser
    MLIRArithDialect
    MLIRFuncDialect
    MLIRPass
    MLIRTransforms
    MLIRRewrite
    MLIRTransformUtils
)