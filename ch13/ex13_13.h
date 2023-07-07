#ifndef SYUAN_EX13_13_H
#define SYUAN_EX13_13_H

#include <iostream>

using std::cout;
using std::endl;

struct X {
  X() { cout << "X()" << endl; }
  X(const X &) { cout << "X(const X&)" << endl; }

  X &operator=(const X &) {
    cout << "operator=" << endl;

    return *this;
  }

  ~X() { cout << "~X()" << endl; }
};

#endif // SYUAN_EX13_13_H