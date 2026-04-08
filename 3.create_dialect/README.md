# 创建方言
本示例展示如何在MLIR中创建一个名为Cat的方言并加载到MLIR中。参考MLIR项目，目录结构为：
```
.
├── CMakeLists.txt
├── include
│   ├── Cat
│   │   ├── CMakeLists.txt
│   │   └── IR
│   │       ├── CatDialect.h
│   │       ├── CatDialect.td
│   │       └── CMakeLists.txt
│   └── CMakeLists.txt
├── lib
│   ├── Cat
│   │   ├── CMakeLists.txt
│   │   └── IR
│   │       ├── CatDialect.cpp
│   │       └── CMakeLists.txt
│   └── CMakeLists.txt
├── main.cpp
└── README.md
```

## 1、定义[Dialect.td](include/Cat/IR/CatDialect.td)文件
td文件需要包含OpBase.td ，该文件是 MLIR 的 TableGen 基础定义文件，属于 ODS 基础库。新建方言需要继承Dialect基类，方言类中的变量含义可以参考Dialect基类的定义。TableGen语法参考[官方文档](https://llvm.org/docs/TableGen/ProgRef.html#introduction)

## 2、TableGen生成文件
在include相应方言IR的[CMakeLists](include/Cat/IR/CMakeLists.txt)中书写生成语法。
在lib相应方言IR的[CMakeLists](lib/Cat/IR/CMakeLists.txt)中书写依赖include中的构建目标。

## 3、创建头文件和库文件
[头文件](include/Cat/IR/CatDialect.h)引入TableGen生成的头文件。[库文件](lib/Cat/IR/CatDialect.cpp)引入[头文件](include/Cat/IR/CatDialect.h)和TableGen生成的库文件。后续还会在[库文件](lib/Cat/IR/CatDialect.cpp)中对方言进行初始化(加载op等)以及实现一些函数。

## 4、加载方言
在需要的[地方](./main.cpp)使用MLIRContext的loadDialect加载方言。