# chapter13 拷贝控制


## 1.拷贝、赋值、销毁
### 拷贝构造函数
- **what**: 如果一个构造函数的第一个形参是**自身类型的引用**，而且其他参数都有默认值，则此构造函数称为**拷贝构造函数**，`class Foo { public: Foo(const Foo&); }`
  - 不能是explicit的，因为拷贝构造函数在几种情况下会被隐式的调用。
  - 即使我们定义了其他构造函数(非拷贝)，编译器也会为我们合成一个拷贝构造函数。
    - 编译器把给定对象中的每个非static的成员拷贝到正在创建的对象中来。
- 拷贝初始化
  - 通常使用拷贝构造函数或者移动构造函数
  - when
    - 用`=`**定义变量**时
    - 将一个对象作为实参传递给一个非引用类型的形参
    - 从一个返回类型是非引用类型的函数中返回一个对象
    - 用花括号列表初始化一个数组中的元素或一个聚合类中的成员
    - insert push是拷贝初始化，emplace是直接初始化
    - 以下共有六处使用了拷贝构造函数
```
Point global;
Point foo_bar(Point arg) // 1
{
	Point local = arg, *heap = new Point(global); // 2: Point local = arg,  3: Point *heap = new Point(global) 
	*heap = local; 
	Point pa[4] = { local, *heap }; // 4, 5
	return *heap;  // 6
}
```
### 拷贝赋值运算符
- `Sales_data trans, accum; trans = accum;` 使用Sales_data的拷贝复制运算符。
- `operator=`函数，左侧对象绑定到this参数， 右侧运算对象作为显式参数传递。
  - 可被重载
- `Foo& operator=(const Foo&);`
- 合成拷贝复制运算符：如果一个类未定义自己的拷贝复制运算符，编译器会生成一个。

### 析构函数
- `~Foo(){}`，没有返回值，也不接受参数。
  - 执行过程
    - 1.执行函数体
    - 2.析构成员
      - 成员按照逆序销毁
  - 析构函数自身并不直接销毁成员。成员是在析构函数体之后隐含的析构阶段被销毁的。
- When
  - 变量离开其作用域时
  - 当一个对象被销毁时，其成员被销毁
  - 容器被销毁时，其元素被销毁
  - 指针 //TODO
  - 对于临时对象，当创建它的完整表达式结束时被销毁
```
bool fcn(const Sales_data *trans, Sales_data accum)
{
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}
// accum, item1 and item2 会发生析构
```
- 合成析构函数
  - 一个类未定义自己的析构函数时，编译器会为它定义一个**合成析构函数**

### 三/五法则

### 使用=default

### 阻止拷贝

## 2.拷贝控制和资源管理
### 行为像值的类

### 定义行为像指针的类

## 3.交换操作

## 4.拷贝控制示例

## 5.动态内存管理类

## 6.对象移动
### 右值引用

### 移动构造函数与移动赋值运算符

### 右值引用和成员函数