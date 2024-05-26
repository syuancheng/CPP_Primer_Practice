#include "ex13_44_string.h"
#include <memory>
#include <utility>

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) {
  auto str = alloc.allocate(e - b);
  return std::make_pair(str, std::uninitialized_copy(b, e, str));
}
