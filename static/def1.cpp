#include <iostream>

int myFunction() {
  static int count = 0; // Static local variable
  count++;

  return count;
}

// Usage
int main() {

  auto c1 = myFunction();

  auto c2 = myFunction();

  std::cout << c1 << std::endl;
  std::cout << c2 << std::endl;

  return 0;
}
