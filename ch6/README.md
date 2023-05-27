## ch6 函数

#### 6.1
形参：申明在函数参数列表中的本地变量。他们被初始化通过实参在方法调用的时候。
实参：在方法调用中提供值来初始化形参。

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