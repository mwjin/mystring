#include "mystring.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <cstring>

namespace mystring {
namespace {

TEST(MyStringTest, InitEmptyString) {
  MyString str{};
  EXPECT_EQ(str.length(), 0);
  EXPECT_EQ(strcmp(str.c_str(), ""), 0);
}

TEST(MyStringTest, InitWithNullPtr) {
  MyString str{nullptr};
  EXPECT_EQ(str.length(), 0);
  EXPECT_EQ(str.c_str(), nullptr);
}

TEST(MyStringTest, InitWithString) {
  MyString str{"hello"};
  EXPECT_EQ(str.length(), 5);
  EXPECT_EQ(strcmp(str.c_str(), "hello"), 0);
}

TEST(MyStringTest, CopyMyString) {
  MyString src{"World!"};
  MyString dst{src};
  EXPECT_EQ(strcmp(src.c_str(), "World!"), 0);
  EXPECT_EQ(src.length(), dst.length());
  EXPECT_EQ(strcmp(src.c_str(), dst.c_str()), 0);
}

TEST(MyStringTest, AssignMyString) {
  MyString src{"hello"};
  MyString dst{};
  dst = src;
  EXPECT_EQ(strcmp(src.c_str(), "hello"), 0);
  EXPECT_EQ(src.length(), dst.length());
  EXPECT_EQ(strcmp(src.c_str(), dst.c_str()), 0);
}

TEST(MyStringTest, AssignShorterString) {
  MyString src{"Hi"};
  MyString dst{"Hello"};
  dst = src;
  EXPECT_EQ(strcmp(src.c_str(), "Hi"), 0);
  EXPECT_EQ(src.length(), dst.length());
  EXPECT_EQ(strcmp(src.c_str(), dst.c_str()), 0);
}

TEST(MyStringTest, AssignMyself) {
  MyString src{"hello"};
  src = src;
  EXPECT_EQ(strcmp(src.c_str(), "hello"), 0);
}

TEST(MyStringTest, ExtendString) {
  MyString dst{"Hello"};
  MyString src{", World!"};
  dst += src;
  EXPECT_EQ(strcmp(dst.c_str(), "Hello, World!"), 0);
}

TEST(MyStringTest, ExtendRawString) {
  MyString dst{"Hello"};
  const char* src{", World!"};
  dst += src;  // Expect implicit construction
  EXPECT_EQ(strcmp(dst.c_str(), "Hello, World!"), 0);
}

TEST(MyStringTest, ConcatStrings) {
  MyString str1{"Hello"};
  MyString str2{", World!"};
  MyString result{str1 + str2};
  EXPECT_EQ(strcmp(result.c_str(), "Hello, World!"), 0);
}

TEST(MyStringTest, TwoStringEQ) {
  MyString str{"a"};
  EXPECT_TRUE(str == "a");
  EXPECT_FALSE(str == "b");
  EXPECT_FALSE(str == "ab");
}

TEST(MyStringTest, TwoStringNE) {
  MyString str{"a"};
  EXPECT_FALSE(str != "a");
  EXPECT_TRUE(str != "b");
  EXPECT_TRUE(str != "ab");
}

TEST(MyStringTest, TwoStringLess) {
  MyString str{"a"};
  EXPECT_FALSE(str < "a");
  EXPECT_TRUE(str < "b");
  EXPECT_TRUE(str < "ab");
}

TEST(MyStringTest, TwoStringLE) {
  MyString str{"c"};
  EXPECT_TRUE(str <= "c");
  EXPECT_FALSE(str <= "b");
  EXPECT_TRUE(str <= "cb");
}

TEST(MyStringTest, TwoStringGreater) {
  MyString str{"b"};
  EXPECT_TRUE(str > "a");
  EXPECT_FALSE(str > "b");
  EXPECT_TRUE(str > "ab");
}

TEST(MyStringTest, TwoStringGE) {
  MyString str{"b"};
  EXPECT_TRUE(str >= "a");
  EXPECT_TRUE(str >= "b");
  EXPECT_FALSE(str >= "bc");
}

TEST(MyStringTest, GetSubstring) {
  MyString str{"Hello, World!"};
  EXPECT_EQ(str.substr(3, 2), "lo");
}

TEST(MyStringTest, GetSubstrNoArgs) {
  MyString str{"Hello, World!"};
  EXPECT_EQ(str.substr(), "Hello, World!");
}

TEST(MyStringTest, GetSubstrOnlyPos) {
  MyString str{"Hello, World!"};
  EXPECT_EQ(str.substr(5), ", World!");
}

TEST(MyStringTest, Reserve) {
  MyString str{"Hello, World!"};
  str.reserve(100);
  EXPECT_EQ(str, "Hello, World!");
  EXPECT_EQ(str.length(), 13);
  EXPECT_EQ(str.capacity(), 100);
}

TEST(MyStringTest, InsertString) {
  MyString dst{"He, World!"};
  MyString src{"llo"};
  dst.insert(2, src);
  EXPECT_EQ(dst, "Hello, World!");
}

TEST(MyStringTest, InsertStringAfterReserving) {
  MyString dst{"He, World!"};
  MyString src{"llo"};
  dst.reserve(100);
  dst.insert(2, src);
  EXPECT_EQ(dst, "Hello, World!");
}

TEST(MyStringTest, InsertStringFirstPos) {
  MyString dst{"llo, World!"};
  MyString src{"He"};
  dst.insert(0, src);
  EXPECT_EQ(dst, "Hello, World!");
}

TEST(MyStringTest, InsertStringLastPos) {
  MyString dst{"Hello, Wo"};
  MyString src{"rld!"};
  dst.insert(dst.length(), src);
  EXPECT_EQ(dst, "Hello, World!");
}

TEST(MyStringTest, InsertRawString) {
  MyString dst{"llo, World!"};
  dst.insert(0, "He");
  EXPECT_EQ(dst, "Hello, World!");
}

TEST(MyStringTest, InsertCharacter) {
  MyString dst{"Hllo, World!"};
  dst.insert(1, 'e');
  EXPECT_EQ(dst, "Hello, World!");
}

TEST(MyStringTest, ExtendUsingInsert) {
  MyString dst{};
  dst.insert(0, "Hello, World!");
  EXPECT_EQ(dst, "Hello, World!");
}

TEST(MyStringTest, ExtendUsingInsertAfterReserve) {
  MyString dst{};
  dst.reserve(100);
  dst.insert(0, "Hello, World!");
  EXPECT_EQ(dst, "Hello, World!");
}

TEST(MyStringTest, EraseSubstring) {
  MyString str{"This is an example sentence."};
  str.erase(9, 9);
  EXPECT_EQ(str, "This is a sentence.");
}

TEST(MyStringTest, EraseStringUntilEnd) {
  MyString str{"This is an example sentence."};
  str.erase(18, 10);
  EXPECT_EQ(str, "This is an example");
}

TEST(MyStringTest, EraseStringExceedLength) {
  MyString str{"This is an example sentence."};
  str.erase(18, 100);
  EXPECT_EQ(str, "This is an example");
}

TEST(MyStringTest, EraseWholeString) {
  MyString str{"This is an example sentence."};
  str.erase(0, str.length());
  EXPECT_EQ(str, "");
}

TEST(MyStringTest, FindSubstr) {
  MyString str{"This is an example sentence."};
  EXPECT_EQ(str.find("example"), 11);
}

TEST(MyStringTest, FindSubstrNotFound) {
  MyString str{"This is an example sentence."};
  EXPECT_EQ(str.find("example", 12), -1);
}

TEST(MyStringTest, FindSubstrDiffPos) {
  MyString str{"I'm very very strong!"};
  EXPECT_EQ(str.find("very"), 4);
  EXPECT_EQ(str.find("very", 8), 9);
}

}  // namespace
}  // namespace mystring
