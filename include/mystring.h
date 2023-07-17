
#include <cstddef>

class MyString {
 public:
  MyString(char c);
  MyString(char* s);
  MyString(const MyString& other);
  ~MyString();
  MyString& operator=(const MyString* other);

 private:
  char* str_;
  std::size_t len_;
};
