

class A {
public:
  A() : _i(0) {}
  A(int i) : _i(i) {}
  //补充
  A(const A &a)
      : _i(a._i) {
  } //为什么引用？
    //如果拷贝构造函数的参数不是引用类型，而是值类型（即直接传递对象），在调用拷贝构造函数时，需要将对象以值传递给该函数。这就意味着要再次调用拷贝构造函数来创建这个对象的副本，这会导致无限递归调用，直到栈溢出。
  //赋值构造函数
private:
  int _i;
};

class B {
public:
  //拷贝构造
  B(const B &b) : _a(new A(*b._a)) {}

  B(const B &&b) : _a(b._a) { b._a = nullptr; }

private:
  A *_a;
  static int t;
};