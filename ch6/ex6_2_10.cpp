#include <iostream>

void exchange_value(int *a, int *b) {
  std::cout << "A=" << &a << " ,B=" << &b << std::endl;
  //   int tmp = *a;
  //   *a = *b;
  //   *b = tmp;
}

int main() {
  int a = 2, b = 3;

  int *pA = &a;
  int *pB = &b;
  std::cout << "pA=" << &pA << " ,pB=" << &pB << std::endl;
  exchange_value(pA, pB);
  //   std::cout << "pA=" << pA << " ,pB=" << pB << std::endl;
  //   std::cout << "a=" << a << " , b=" << b << std::endl;

  return 0;
}