# chapter12 动态内存
- 分配在静态或栈内存中的对象由**编译器自动创建和销毁**。
  - 栈对象仅在其定义的程序块运行时才存在。
  - static对象在使用之前分配，在程序结束时销毁。
- 内存池：堆(heap)
  - 存储动态分配的对象（**动态对象**：程序运行时分配的对象）

## 动态内存与指针指针
- 动态内存管理`new + delete`
  - new: 分配空间，并返回一个指向该对象的指针。
  - delete: 接受一个动态对象的指针，销毁该对象，并释放与之关联的内存。
  - 没有delete会内存泄露，delete了还有引用的对象会导致非法内存指针。
- 指针指针`shared_ptr unique_ptr weak_ptr`
  - shared_ptr: 允许多个指针指向同一个对象
  - unique_ptr: 独占所指向的对象
  - weak_ptr: 指向shared_ptr所管理的对象

### shared_ptr类
- 支持的操作
  - `shared_ptr<T> sp`:空指针指针，可以指向类型为T的对象
  - `if(p)`将p作为一个条件判断，若指向一个对象，则为true
  - `*p`解引用，获得它指向的对象
  - `p->mem` <=>  `(*p).mem`
  - `p->get()` 返回p中保存的指针
  - `swap(p, q); p.swap(q);` 交换p和q中保存的指针
  - `make_shared<T>(args)` 返回一个shared_ptr，指向动态分配的对象，其类型为T，使用args来初始化的。
    - 创建的参数必须与T的某个构造函数相匹配。
  - `shared_ptr<T>p(q)`: p是shared_ptr q的拷贝；会使q中的计数器增加。
  - `p=q`p和q都是shared_ptr，递减p的引用计数，增加q的引用计数。
- shared_ptr的拷贝和赋值
  - 在进行拷贝或赋值的时候，**每个**shared_ptr都会记录有多少个其他shared_ptr指向**相同**的对象。
    -  引用计数增加
       -  使用一个shared_ptr初始化另一个shared_ptr
       -  将shared_ptr作为参数传给一个函数
       -  作为函数的返回值
    - 引用计数递减
      - 当给一个shared_ptr赋予新值
      - shared_ptr被销毁；局部的shared_ptr离开作用域
    - 一旦计数器变为0，就会自动释放自己管理的对象
- shared_ptr自动销毁所管理的对象
  - shared_ptr的析构函数会递减它所指向的对象的引用计数，如果引用计数变为0，shared_ptr的析构函数就会销毁对象，并释放占用的内存
- shared_ptr如果被存放在容器中，而后不再需要全部元素，只是使用期中一部分，那么需要手动erase不需要的元素。
- 程序使用动态内存的原因：
  - 1. 程序不知道自己需要多少对象；容器类
  - 2. 程序不知道所需对象的准确类型
  - 3. 程序需要在多个对象间共享数据
- 
