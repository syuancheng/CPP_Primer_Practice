#ifndef D41758A6_CAEB_4B23_AF9D_C04FA89C2695
#define D41758A6_CAEB_4B23_AF9D_C04FA89C2695

#include <memory>
class String {
  String(const char *);
  String(const String &);
  String &operator=(const String &);

  //TODO: add rvalue func

  ~String();

private:
  std::pair<char *, char *> alloc_n_copy(const char *, const char *);
  void range_initializer(const char *, const char *);
  void free();

private:
  char *elements;
  char *end;
  std::allocator<char> alloc;
};

#endif /* D41758A6_CAEB_4B23_AF9D_C04FA89C2695 */
