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
  char at(std::size_t pos) const;
  void reserve(std::size_t size);
  MyString& insert(std::size_t pos, const MyString& rhs);
  const char* c_str() const;
  std::size_t length() const;
  std::size_t capacity() const;

 private:
  void swap(MyString& rhs);
  char* str_ = nullptr;
  std::size_t len_ = 0;
  std::size_t capacity_ = 0;
  static const std::size_t npos = -1;
};

MyString operator+(const MyString& str1, const MyString& str2);
bool operator==(const MyString& str1, const MyString& str2);
bool operator!=(const MyString& str1, const MyString& str2);
bool operator<(const MyString& str1, const MyString& str2);
bool operator<=(const MyString& str1, const MyString& str2);
bool operator>(const MyString& str1, const MyString& str2);
bool operator>=(const MyString& str1, const MyString& str2);
