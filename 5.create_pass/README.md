# 创建pass
本示例展示如何创建并使用pass，在本节中我们将要实现两个pass，第一个pass完成Cat方言中Add OP的规范化实现自动简化x+0->x，第二个pass实现cat.add转换为arith.addi。
```
.
├── CMakeLists.txt
├── include
│   ├── Cat
│   │   ├── CMakeLists.txt
│   │   ├── IR
│   │   │   ├── CatDialect.h
│   │   │   ├── CatDialect.td
│   │   │   ├── CatOps.h
│   │   │   ├── CatOps.td
│   │   │   └── CMakeLists.txt
│   │   └── Transforms
│   │       ├── CMakeLists.txt
│   │       ├── Passes.h
│   │       └── Passes.td
│   └── CMakeLists.txt
├── lib
│   ├── Cat
│   │   ├── CMakeLists.txt
│   │   ├── IR
│   │   │   ├── CatDialect.cpp
│   │   │   ├── CatOps.cpp
│   │   │   └── CMakeLists.txt
│   │   └── Transforms
│   │       ├── CatCanonicalizer.cpp
│   │       └── CMakeLists.txt
│   └── CMakeLists.txt
├── main.cpp
└── README.md
```

## 1、定义[Pass.td](include/Cat/Transforms/Passes.td)文件

## 2、TableGen生成文件
在include相应方言IR的[CMakeLists](include/Cat/Transforms/CMakeLists.txt)中书写op生成语法。
在lib相应方言IR的[CMakeLists](lib/Cat/Transforms/CMakeLists.txt)中书写依赖include中的构建目标。

## 3、创建头文件和库文件
[头文件](include/Cat/Transforms/Passes.h)引入TableGen生成的头文件。

[库文件](lib/Cat/Transforms/CatCanonicalizer.cpp)引入[头文件](include/Cat/Transforms/Passes.h)和TableGen生成的库文件。重写runOnOperation方法实现pass逻辑。

## 4、使用
在[main](main.cpp)中注册pass并将其添加到module上进行使用。