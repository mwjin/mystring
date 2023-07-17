#include <cstddef>

class MyString {
 public:
  MyString();
  MyString(char c);
  MyString(const char* s);
  MyString(const MyString& other);
  ~MyString();
  MyString& operator=(const MyString& other);

  const char* str() const;
  int length() const;

 private:
  char* str_ = nullptr;
  std::size_t len_ = 0;
};
