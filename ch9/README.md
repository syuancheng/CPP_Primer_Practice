# chapter 9 顺序容器

## 1 顺序容器概述
- vector
- deque
- list
- forward_list
- array
- string

## 2 容器概览
### 类型别名
- iterator
- const_iterator
- size_type
- difference_type
- value_type
- reference
- const_reference
### 构造函数
- C c; 默认构造函数， 构造空容器。
- C c1(c2); 构造c2的拷贝c1
- C c1=c2; 相同的容器类型，且保存的是相同的元素类型
- C c(b, e); 构造c，将迭代器b和e指定的范围内的元素拷贝到c(array不支持)
- C c{a, b, c...};列表初始化c
- C c(n) c包含n个元素
- C c(n, t) c包含n个初始值为t的元素
### 赋值与swap
- c1 = c2  将c1中的元素替换为c2中的元素。
- c1 = {a, b, c...} 将c1中的元素替换为列表中的元素(array不支持)
- a.swap(b) 交换a与b中元素
  - a和b必须具有相同的类型，swap通常比从c2向c1拷贝元素快的多。
  - 指向容器的迭代器，引用和指针在swap之后， 仍然指向之前所指向的元素。但是swap之后， 这些元素已经属于不同的容器了。
- swap(a, b) 等于与上一个
### 大小
- c.size() c中元素的个数(不支持forward_list)
- c.max_size() c可保存的最大元素数目
- c.empty() 
### 添加和删除元素
- c.insert(args) 将args中的元素拷贝进c
- c.emplace(inits) 使用inits构造c中的一个元素
- c.earse(args) 删除指定的元素
- c.clear() 删除c的所有元素，返回void

### 关系运算符
- == != 
- <, <=, >, >=
### 获取迭代器
- c.begin(), c.end() 返回指向c首元素和尾元素之后位置的迭代器
- c.cbegin(), c.cend() 返回const_interator

## 3 顺序容器操作
### 添加元素
- c.insert(p,t) 
- c.emplace(p,args) 在迭代器p指向的元素之前， 创建一个由t或者args创建的元素。
- push vs emplace
  - push: 元素类型的对象， 拷贝到容器中
  - emplace： 将参数传递给元素类型的构造函数
### 访问元素
- at和下标操作： 只适用于string，vector， deque和array，返回该元素的引用
- c.back() 返回c中尾元素的引用
- c.front() 返回c中首元素的引用
### 删除元素
- 

## 4 vector对象是如何增长的

## 5 额外的string操作

## 6 容器适配器
