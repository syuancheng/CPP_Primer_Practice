#include "quote.h"
#include <iostream>
#include <string>

class Limit_quote : public Quote {
public:
  Limit_quote() = default;
  Limit_quote(std::string b, double p, size_t m, double d)
      : Quote(b, p), min_count(m), discount(d) {}

  double net_price(size_t s) const override;

  void debug() const override;

private:
  size_t min_count;
  double discount = 0.0;
};