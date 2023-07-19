#include "mystring.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <cstring>

namespace mystring {
namespace {

TEST(MyStringTest, InitEmptyString) {
  MyString str{};
  EXPECT_EQ(str.length(), 0);
  EXPECT_EQ(strcmp(str.str(), ""), 0);
}

TEST(MyStringTest, InitWithNullPtr) {
  MyString str{nullptr};
  EXPECT_EQ(str.length(), 0);
  EXPECT_EQ(str.str(), nullptr);
}

TEST(MyStringTest, InitWithString) {
  MyString str{"hello"};
  EXPECT_EQ(str.length(), 5);
  EXPECT_EQ(strcmp(str.str(), "hello"), 0);
}

TEST(MyStringTest, CopyMyString) {
  MyString src{"World!"};
  MyString dst{src};
  EXPECT_EQ(strcmp(src.str(), "World!"), 0);
  EXPECT_EQ(src.length(), dst.length());
  EXPECT_EQ(strcmp(src.str(), dst.str()), 0);
}

TEST(MyStringTest, AssignMyString) {
  MyString src{"hello"};
  MyString dst{};
  dst = src;
  EXPECT_EQ(strcmp(src.str(), "hello"), 0);
  EXPECT_EQ(src.length(), dst.length());
  EXPECT_EQ(strcmp(src.str(), dst.str()), 0);
}

TEST(MyStringTest, AssignMyself) {
  MyString src{"hello"};
  src = src;
  EXPECT_EQ(strcmp(src.str(), "hello"), 0);
}

TEST(MyStringTest, ExtendString) {
  MyString dst{"Hello"};
  MyString src{", World!"};
  dst += src;
  EXPECT_EQ(strcmp(dst.str(), "Hello, World!"), 0);
}

TEST(MyStringTest, ExtendRawString) {
  MyString dst{"Hello"};
  const char* src{", World!"};
  dst += src;  // Expect implicit construction
  EXPECT_EQ(strcmp(dst.str(), "Hello, World!"), 0);
}

TEST(MyStringTest, ConcatStrings) {
  MyString str1{"Hello"};
  MyString str2{", World!"};
  MyString result{str1 + str2};
  EXPECT_EQ(strcmp(result.str(), "Hello, World!"), 0);
}
}  // namespace
}  // namespace mystring
