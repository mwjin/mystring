#include "mystring.h"

#include <algorithm>
#include <cstring>
#include <memory>
#include <stdexcept>

MyString::MyString() : str_{new char[1]}, len_{0}, capacity_{1} {
  str_[0] = '\0';
}

MyString::MyString(char c) : str_{new char[2]}, len_{1}, capacity_{2} {
  str_[0] = c;
  str_[1] = '\0';
}

MyString::MyString(const char* s) {
  if (s != nullptr) {
    len_ = strlen(s);
    capacity_ = len_ + 1;
    str_ = new char[capacity_];
    for (std::size_t i{}; i < len_; ++i) str_[i] = s[i];
    str_[len_] = '\0';
  }
}

MyString::MyString(const MyString& rhs)
    : str_{new char[rhs.capacity_]}, len_{rhs.len_}, capacity_{rhs.capacity_} {
  for (std::size_t i{}; i < len_; ++i) str_[i] = rhs.str_[i];
  str_[len_] = '\0';
}

MyString::~MyString() {
  if (str_ != nullptr) delete[] str_;
}

MyString& MyString::operator=(const MyString& rhs) {
  if (this == &rhs) return *this;
  if (rhs.len_ < this->capacity_) {
    for (std::size_t i{}; i < rhs.len_; ++i) this->str_[i] = rhs.str_[i];
    this->str_[rhs.len_] = '\0';
    this->len_ = rhs.len_;
  } else {
    MyString tmp{rhs.str_};
    swap(tmp);
  }
  return *this;
}

MyString& MyString::operator+=(const MyString& rhs) {
  if (this->capacity_ - this->len_ > rhs.len_) {
    for (std::size_t i{}; i < rhs.len_; ++i)
      this->str_[this->len_ + i] = rhs.str_[i];
    this->len_ += rhs.len_;
  } else {
    std::size_t str_size{this->len_ + rhs.len_};
    auto new_str{std::make_unique<char[]>(str_size + 1)};
    auto raw_str{new_str.get()};
    for (std::size_t i{}; i < this->len_; ++i) raw_str[i] = this->str_[i];
    for (std::size_t i{}; i < rhs.len_; ++i)
      raw_str[i + this->len_] = rhs.str_[i];

    MyString tmp{raw_str};
    swap(tmp);
  }
  return *this;
}

MyString MyString::substr(std::size_t pos, std::size_t len) const {
  if (pos < 0 || pos >= this->len_)
    throw std::out_of_range("pos is out of the boundary.");
  if (len == npos) len = this->len_ - pos;
  const char* str{this->str_ + pos};
  auto result{std::make_unique<char[]>(len + 1)};
  for (std::size_t i{}; i < len; ++i) result.get()[i] = str[i];
  return result.get();
}

char MyString::at(std::size_t pos) const {
  if (pos < 0 || pos >= len_)
    throw std::out_of_range("pos is out of the boundary");
  return str_[pos];
}

void MyString::reserve(std::size_t size) {
  if (size <= this->capacity_) return;
  char* new_str{new char[size]};
  for (std::size_t i{}; i < this->len_; ++i) new_str[i] = this->str_[i];
  new_str[this->len_] = '\0';
  std::swap(this->str_, new_str);
  this->capacity_ = size;
  delete[] new_str;
}

const char* MyString::str() const { return str_; }
std::size_t MyString::length() const { return len_; }
std::size_t MyString::capacity() const { return capacity_; }

void MyString::swap(MyString& rhs) {
  using std::swap;
  swap(this->str_, rhs.str_);
  swap(this->len_, rhs.len_);
  swap(this->capacity_, rhs.capacity_);
}

MyString operator+(const MyString& str1, const MyString& str2) {
  auto new_str = std::make_unique<char[]>(str1.length() + str2.length() + 1);
  for (std::size_t i{}; i < str1.length(); ++i) new_str.get()[i] = str1.at(i);
  for (std::size_t i{}; i < str2.length(); ++i)
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
