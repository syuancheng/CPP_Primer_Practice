

# 5 编译器暗自为class创建的方法
- 编译器创建
  - default构造函数
  - 拷贝构造函数
  - 析构函数
  - 拷贝复制操作
  

# 6 不适用编译器生成的函数
- 将相应的成员函数声明为私有，并且不实现。 [example](./ch2/rule6.cpp)


# 7 多态基类声明virtual析构函数
- 如果不声明， 将会导致局部销毁对象，导致了内存泄漏。
  - 只有base class部分被销毁 derived class成分没有被销毁。

# 10 赋值相关的运算要返回一个reference *this


# 12 copying函数应该确保复制“对象内所有成员变量”及“所有base class成分”


# 13 

