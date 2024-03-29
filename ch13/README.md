# Chapter13 拷贝控制

## 1.拷贝、赋值、销毁
### 拷贝构造函数
- **what**: 如果一个构造函数的第一个形参是**自身类型的引用**，而且其他参数都有默认值，则此构造函数称为**拷贝构造函数**，`class Foo { public: Foo(const Foo&); }`
  - 不能是explicit的，因为拷贝构造函数在几种情况下会被隐式的调用。
    > Note: `explicit`抑制构造函数的隐式转换
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
    - 对于普通指针， 不会delete它所指的对象
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
- 需要析构函数的类也需要拷贝构造函数和拷贝赋值运算符
- 需要拷贝构造函数的类也需要拷贝赋值运算符

### 使用=default
- 可以将拷贝控制成员定义为`=default`来显示地要求编译器生成合成的版本。
- 当我们在类内用`=default`修饰成员函数，合成的函数将隐式地声明为inline的。
  - 如果不希望是inline，应该在类外定义的时候用`=default`
### 阻止拷贝
- `=delete`加在函数声明时的参数列表后面可以将函数定义为删除的。
  - 必须出现在函数第一次声明的时候。
  - 析构函数不能删除。
- 合成删除的拷贝控制成员
  - 如果一个类有数据成员不能默认构造、拷贝、赋值或销毁，则对应的成员函数将被定义为删除的。

## 2.拷贝控制和资源管理
- 值：  副本和原对象**是完全独立**。如：标准容器库、string
- 指针：副本和原对象**使用相同的底层数据**。如：shared_ptr
- 非值非指针：unique_ptr(不允许拷贝或复制)
### 行为像值的类
[练习 13.22](ex13_22.h)
- 拷贝赋值运算符
  - 将对象赋予它自身，必须能正常工作.(销毁左侧运算对象资源之前，拷贝右侧运算对象)
  - 组合了析构函数和拷贝构造函数的工作
### 行为像指针的类
[练习 13.27](ex13_27.h)
- 引用计数法
## 3.交换操作
- swap
  - 在需要交换两个元素时会调用swap
  - swap函数应该调用swap，而不是std::swap
    - 如果一个类成员有自己的swap函数，那调用std::swap就是错误的
  - Would the pointerlike version of HasPtr benefit from defining a swap function? If so, what is the benefit? If not, why not?
    > Essentially, the specific avoiding memory allocation is the reason why it improve performance. As for the pointerlike version, no dynamic memory allocation anyway. Thus, a specific version for it will not improve the performance.

## 4.拷贝控制示例

## 5.动态内存管理类

## 6.对象移动
### 右值引用

### 移动构造函数与移动赋值运算符

### 右值引用和成员函数