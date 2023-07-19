#include "mystring.h"

#include <algorithm>
#include <cstring>

MyString::MyString() : str_{new char[1]}, len_{0} {}

MyString::MyString(char c) : str_{new char[2]}, len_{1} { str_[0] = c; }

MyString::MyString(const char* s) {
  if (s != nullptr) {
    len_ = strlen(s);
    str_ = new char[len_ + 1];
    strncpy(str_, s, len_);
  }
}

MyString::MyString(const MyString& other) : MyString{other.str_} {}

MyString::~MyString() {
  if (str_ != nullptr) delete[] str_;
}

MyString& MyString::operator=(const MyString& other) {
  if (this == &other) return *this;
  using std::swap;
  MyString tmp{other.str_};
  swap(this->str_, tmp.str_);
  swap(this->len_, tmp.len_);
  return *this;
}

MyString& MyString::operator+=(const MyString& rhs) {
  std::size_t str_size{this->len_ + rhs.len_};
  char* new_str = new char[str_size + 1];
  strncpy(new_str, this->str_, this->len_);
  strncat(new_str, rhs.str_, rhs.len_);

  using std::swap;
  MyString tmp{new_str};
  swap(this->str_, tmp.str_);
  swap(this->len_, tmp.len_);
  return *this;
}

MyString MyString::substr(std::size_t pos, std::size_t len) const {
  if (len == npos) len = this->len_ - pos;
  const char* str{this->str_ + pos};
  char* result{new char[len + 1]};
  strncpy(result, str, len);
  return result;
}

const char* MyString::str() const { return str_; }
int MyString::length() const { return len_; }

MyString operator+(const MyString& str1, const MyString& str2) {
  char* new_str = new char[str1.length() + str2.length() + 1];
  strncpy(new_str, str1.str(), str1.length());
  strncat(new_str, str2.str(), str2.length());
  return new_str;
}

bool operator==(const MyString& str1, const MyString& str2) {
  return strcmp(str1.str(), str2.str()) == 0;
}

bool operator!=(const MyString& str1, const MyString& str2) {
  return strcmp(str1.str(), str2.str()) != 0;
}

bool operator<(const MyString& str1, const MyString& str2) {
  return strcmp(str1.str(), str2.str()) < 0;
}

bool operator<=(const MyString& str1, const MyString& str2) {
  return strcmp(str1.str(), str2.str()) <= 0;
}

bool operator>(const MyString& str1, const MyString& str2) {
  return strcmp(str1.str(), str2.str()) > 0;
}

bool operator>=(const MyString& str1, const MyString& str2) {
  return strcmp(str1.str(), str2.str()) >= 0;
}
