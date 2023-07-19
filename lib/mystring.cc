#include "mystring.h"

#include <algorithm>
#include <cstring>
#include <memory>
#include <stdexcept>

MyString::MyString() : str_{new char[1]}, len_{0} {}

MyString::MyString(char c) : str_{new char[2]}, len_{1} { str_[0] = c; }

MyString::MyString(const char* s) {
  if (s != nullptr) {
    len_ = strlen(s);
    str_ = new char[len_ + 1];
    strcpy(str_, s);
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
  auto new_str{std::make_unique<char[]>(str_size + 1)};
  strcpy(new_str.get(), this->str_);
  strcat(new_str.get(), rhs.str_);

  using std::swap;
  MyString tmp{new_str.get()};
  swap(this->str_, tmp.str_);
  swap(this->len_, tmp.len_);
  return *this;
}

MyString MyString::substr(std::size_t pos, std::size_t len) const {
  if (pos >= this->len_) throw std::out_of_range("pos is out of the boundary.");
  if (len == npos) len = this->len_ - pos;
  const char* str{this->str_ + pos};
  auto result{std::make_unique<char[]>(len + 1)};
  strncpy(result.get(), str, len);
  return result.get();
}

const char* MyString::str() const { return str_; }
int MyString::length() const { return len_; }

MyString operator+(const MyString& str1, const MyString& str2) {
  auto new_str = std::make_unique<char[]>(str1.length() + str2.length() + 1);
  strcpy(new_str.get(), str1.str());
  strcat(new_str.get(), str2.str());
  return new_str.get();
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
