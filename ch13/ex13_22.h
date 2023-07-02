#ifndef SYUAN_EX13_22_H
#define SYUAN_EX13_22_H


#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): i(0), ps(new std::string(s)) {}
    HasPtr(const HasPtr& hp): i(hp.i), ps(new std::string(*hp.ps)) {}

    HasPtr& operator=(const HasPtr& rhs) {
        auto new_p = new std::string(*rhs.ps);
        delete ps; //必须删除原本的指向的对象， 不然就内存泄露了。

        i = rhs.i;
        ps = new_p;

        return *this;
    }

    ~HasPtr() {
        delete ps;
    }

private:
    int i;
    std::string *ps;
};

#endif // SYUAN_EX13_22_H