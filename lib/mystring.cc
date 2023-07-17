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
  using std::swap;
  MyString tmp{other.str_};
  swap(this->str_, tmp.str_);
  swap(this->len_, tmp.len_);
  return *this;
}

const char* MyString::str() const { return str_; }
int MyString::length() const { return len_; }
