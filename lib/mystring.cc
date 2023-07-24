#include "mystring.h"

#include <algorithm>
#include <cstring>
#include <memory>
#include <stdexcept>

MyString::MyString() : str_{new char[1]}, len_{0}, capacity_{0} {}

MyString::MyString(char c) : str_{new char[2]}, len_{1}, capacity_{1} {
  str_[0] = c;
}

MyString::MyString(const char* s) {
  if (s != nullptr) {
    len_ = strlen(s);
    capacity_ = len_;
    str_ = new char[len_ + 1];
    for (int i{}; i < len_; ++i) str_[i] = s[i];
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
  auto raw_str{new_str.get()};
  for (int i{}; i < this->len_; ++i) raw_str[i] = this->str_[i];
  for (int i{}; i < rhs.len_; ++i) raw_str[i + this->len_] = rhs.str_[i];

  using std::swap;
  MyString tmp{raw_str};
  swap(this->str_, tmp.str_);
  swap(this->len_, tmp.len_);
  return *this;
}

MyString MyString::substr(std::size_t pos, std::size_t len) const {
  if (pos < 0 || pos >= this->len_)
    throw std::out_of_range("pos is out of the boundary.");
  if (len == npos) len = this->len_ - pos;
  const char* str{this->str_ + pos};
  auto result{std::make_unique<char[]>(len + 1)};
  for (int i{}; i < len; ++i) result.get()[i] = str[i];
  return result.get();
}

char MyString::at(std::size_t pos) const {
  if (pos < 0 || pos >= len_)
    throw std::out_of_range("pos is out of the boundary");
  return str_[pos];
}

const char* MyString::str() const { return str_; }
std::size_t MyString::length() const { return len_; }
std::size_t MyString::capacity() const { return capacity_; }

MyString operator+(const MyString& str1, const MyString& str2) {
  auto new_str = std::make_unique<char[]>(str1.length() + str2.length() + 1);
  for (int i{}; i < str1.length(); ++i) new_str.get()[i] = str1.at(i);
  for (int i{}; i < str2.length(); ++i)
    new_str.get()[i + str1.length()] = str2.at(i);
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
