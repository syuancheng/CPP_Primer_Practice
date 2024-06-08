#include "quote.h"
#include <iostream>
#include <string>

class Limit_quote : public Quote {
public:
  Limit_quote() = default;
  Limit_quote(std::string b, double p, size_t m, double d)
      : Quote(b, p), min_count(m), discount(d) {}

  double net_price(size_t s) const override {
    if (s > min_count) {
      return s * price * (1 - discount);
    }
    return s * price;
  }

  void debug() const override {
    Quote::debug();
    std::cout << "min_count= " << this->min_count
              << " ,discount= " << this->discount;
  }

private:
  size_t min_count;
  double discount = 0.0;
};