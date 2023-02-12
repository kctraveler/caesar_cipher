#include "decoder.hpp"
#include "utils.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(Utils, EncryptTest) {
  EXPECT_EQ(encrypt("HELLO WORLD", 3), "KHOOR ZRUOG");
}

TEST(Utils, DecryptTest) {
  EXPECT_EQ(encrypt("KHOOR ZRUOG", 3, true), "HELLO WORLD");
}

TEST(Utils, CreateDictTest) {
  std::set<string> dict = create_dict("./words.txt");
  EXPECT_EQ(dict.size(), 90107);
}