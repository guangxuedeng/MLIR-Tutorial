# OpBuilder
在 MLIR 中，一个完整的操作（Operation）非常复杂。如果你想徒手通过底层 API 创建一条简单的加法指令，你需要先构建一个 OperationState，把操作名、位置信息、输入参数（Operands）、结果类型（Result Types）以及属性（Attributes）全塞进去，最后再分配内存。

OpBuilder 是 MLIR 中用来生成 IR 树枝叶的最核心工具。它管理着生成代码时的上下文位置，并提供了极度友好的 C++ 泛型接口。

下是 OpBuilder 的三个核心机制：
1. 插入点 (Insertion Point)：类似文本编辑器里打字时的闪烁光标。
2. create<OpTy>(...)工厂，当调用 builder.create<...>(...) 时，OpBuilder 会在后台自动完成：
    1. 收集你传入的参数。
    2. 生成 OperationState。
    3. 调用底层接口创建 Operation。
    4. 将创建好的 Operation 自动插入到当前“光标”所在的位置。
    5. 返回新操作的结果（通常可以隐式转换为 mlir::Value 供下一条指令使用）。
3. Context代理：OpBuilder 把 MLIRContext 的常用方法做了一层便捷封装，因此不需要到处传context指针，直接从builder获取即可。