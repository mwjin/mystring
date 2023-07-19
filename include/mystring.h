#include <cstddef>

class MyString {
 public:
  MyString();
  MyString(char c);
  MyString(const char* s);
  MyString(const MyString& rhs);
  ~MyString();
  MyString& operator=(const MyString& rhs);
  MyString& operator+=(const MyString& rhs);
  MyString substr(std::size_t pos = 0, std::size_t len = npos) const;

  const char* str() const;
  int length() const;

 private:
  char* str_ = nullptr;
  std::size_t len_ = 0;
  static const std::size_t npos = -1;
};

MyString operator+(const MyString& str1, const MyString& str2);
bool operator==(const MyString& str1, const MyString& str2);
bool operator!=(const MyString& str1, const MyString& str2);
bool operator<(const MyString& str1, const MyString& str2);
bool operator<=(const MyString& str1, const MyString& str2);
bool operator>(const MyString& str1, const MyString& str2);
bool operator>=(const MyString& str1, const MyString& str2);
