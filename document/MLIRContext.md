# MLIRContext
MLIRContext是整个 MLIR 编译过程的全局注册表、内存分配器和大管家。在任何 MLIR 程序开始构建、解析或转换 IR之前，首先必须创建的实例就是 MLIRContext。所有的模块（Module）、函数（Function）、操作（Operation）、类型（Type）和属性（Attribute）都直接或间接地与一个 MLIRContext 绑定。
## 对象唯一化
当你向 MLIRContext 请求一个 32位整数类型 时，它会检查其内部的哈希表中是否已经存在这个类型。如果存在，就直接返回现有对象的指针；如果不存在，则创建一个新的并存入哈希表。

因为保证了值的唯一性，MLIR 比较两个类型或属性是否相同时，不需要比较它们的内容，只需要比较它们的指针地址即可。
## 方言注册管理
## 内存生命周期管理
MLIRContext 的内存管理使用基于区域的 Bump-pointer allocator，即碰撞指针分配器，主要管理的是那些“不可变（Immutable）”且需要“全局唯一化（Uniqued）”的基础组件。

管理对象(随Context生命周期一致)包括：类型(Type)、属性(Attribute)、位置信息(Location)、字符串和标识符(Identifiers/StringData)、方言实例及其注册信息。

不管理的对象：操作(Operation)、基本块(Block)、区域(Region)、值(Value)。
## 多线程与线程安全
MLIRContext允许整个编译流水线（Pass Manager）在多个线程中并行处理不同的函数或模块，同时安全地共享同一个底层的全局状态（即 MLIRContext）。
初始化（单线程）：在 main 函数中，创建一个 MLIRContext，并加载所有需要的方言。

构建 IR（通常单线程）：解析 .mlir 文本文件或通过前端（如 Clang/TensorFlow）生成初始的 IR 树（Module 包含一堆 Function）。

运行过程：
1. 初始化（单线程）：在 main 函数中，创建一个 MLIRContext，并加载所有需要的方言。
2. 建 IR（通常单线程）：解析 .mlir 文本文件或通过前端（如 Clang/TensorFlow）生成初始的 IR 树（Module 包含一堆 Function）。
3. 并发优化（多线程）：将 Module 交给 PassManager。

    1. PassManager 发现有 100 个互相独立的 func.func。
    2. 它会启动一个线程池，将这 100 个函数分发给不同的线程。
    3. 线程 A 修改 func 1 的 IR，线程 B 修改 func 2 的 IR（由于它们修改的是互不相交的内存区域，所以是安全的）。
    4. 在修改的过程中，线程 A 和 B 会频繁地向同一个 MLIRContext 请求新的 Types 和 Attributes，由于 Context 的获取操作是线程安全的，整个过程无比丝滑。