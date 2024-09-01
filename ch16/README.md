# Chapter16

## 函数模板(公式)
- `template <typename T> int compare(const T &v1, const T &v2){}`
- 函数模板是一个公式， 给一个特定类型， 就会生成该类型的函数版本。 [hello world](./16.1/example1.cpp)
- 以关键字template开始， 后跟一个模板参数列表，用<>包围起来。
  - 模板参数列表：用逗号分割的一个或多个模板参数。
    - 模板参数：在类或函数定义中用到的类型或值。
- 实例化函数模板：编译器使用模板实参代替对应的模板参数来创建出模板的一个实例。
- 非类型模板参数：表示一个值而非一个类型。实参必须是常量表达式。template <class T, size_t N> void array_init(T (&parm)[N]){}
- 内联函数模板： `template <typename T> inline T min(const T&, const T&);`
- 函数模板和类模板成员函数的定义通常放在头文件中。