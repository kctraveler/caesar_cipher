#include "decoder.hpp"
#include "utils.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

/*
   Test that checks if 'HELLO WORLD' is encrypted with a key of 3.
*/

TEST(Utils, EncryptTest) {
  EXPECT_EQ(encrypt("HELLO WORLD", 3), "KHOOR ZRUOG");
}

/*
   Test that checks if 'KHOOR ZROUG' is decrypted with a key of 3.
*/

TEST(Utils, DecryptTest) {
  EXPECT_EQ(encrypt("KHOOR ZRUOG", 3, true), "HELLO WORLD");
}

/*
   Test that checks if the updated word list has 90107 words, the correct number of words after it is filtered to include words with a length of 3 or more characters and includes words with no special characters. 
*/
TEST(Utils, CreateDictTest) {
  std::set<string> dict = create_dict("./words.txt");
  EXPECT_EQ(dict.size(), 90107);
}