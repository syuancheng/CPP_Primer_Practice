#include <string>

template <T> class NamedObject {
public:
  NamedObject(std::string& name, const T& value);

private:
  std::string &nameValue;
  const T objectValue;
};