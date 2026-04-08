# 创建OP
本示例展示如何为Cat方言创建一个名为Add的op并用该op创建一段MLIR。参考MLIR项目，目录结构为：
```
.
├── CMakeLists.txt
├── include
│   ├── Cat
│   │   ├── CMakeLists.txt
│   │   └── IR
│   │       ├── CatDialect.h
│   │       ├── CatDialect.td
│   │       ├── CatOps.h
│   │       ├── CatOps.td
│   │       └── CMakeLists.txt
│   └── CMakeLists.txt
├── lib
│   ├── Cat
│   │   ├── CMakeLists.txt
│   │   └── IR
│   │       ├── CatDialect.cpp
│   │       ├── CatOps.cpp
│   │       └── CMakeLists.txt
│   └── CMakeLists.txt
├── main.cpp
└── README.md
```

## 1、定义[Ops.td](include/Cat/IR/CatOps.td)文件

## 2、TableGen生成文件
在include相应方言IR的[CMakeLists](include/Cat/IR/CMakeLists.txt)中书写op生成语法。

## 3、创建头文件和库文件
[头文件](include/Cat/IR/CatOps.h)引入TableGen生成的头文件。[库文件](lib/Cat/IR/CatOps.cpp)引入[头文件](include/Cat/IR/CatOps.h)和TableGen身成的库文件。

## 4、加载Op
在[Dialect库文件](lib/Cat/IR/CatDialect.cpp)的initialize方法中加载Ops。