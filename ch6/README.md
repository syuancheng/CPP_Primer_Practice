## ch6 函数

#### 6.1
形参：申明在函数参数列表中的局部变量。他们被初始化通过实参在方法调用的时候。
实参：在方法调用中提供值来初始化形参。
局部变量: 定义在一个块中的变量。
局部静态变量：它在程序的执行路径第一次经过对象的定义语句时初始化，知道程序终止才被销毁，方法执行结束并不会销毁。
形参+函数体内部定义的变量=局部变量

值传递：
实参的值拷贝给形参，形参和实参是两个互相独立的对象。

引用传递：
形参是引用类型，引用形参是它对应的实参的别名。
（如果函数无需修改引用形参的值时，最好使用常量引用）

指针传递：
同样是拷贝操作

#### 6.2
```
int f() {
    string s;

    return s; //return wrong type
}

f2(int i) { /* ... */} //need void

int calc(int v1, int v1) /* ... */ } //use the same parameter name, and lack of {

double square(double x) return x*x // func body needs braces
```

#### 6.3