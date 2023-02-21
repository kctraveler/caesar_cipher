#include "utils.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/**
 * Takes the filepath to a list of words and cleans up the input to meet
 * the requirements of the dictionary for the Ceasar Cipher. Words are all 3
 * or more characters long, no special characters, and coverted to all
 * capital letters.
 * @param file_path    The file path containing the list of words
 * @return             A set of the words that meet our requirments
 */
set<string> create_dict(string file_path) {
  set<string> words;
  fstream words_file;
  words_file.open(file_path);
  if (words_file.is_open()) {
    string line;
    while (getline(words_file, line)) {
      if (line.find_first_of(SPECIAL_CHARACTERS) == string::npos &&
          line.length() >= 3) {
        transform(line.begin(), line.end(), line.begin(), ::toupper);
        words.insert(line);
      }
    }
  }
  words_file.close();
  return words;
}

/**
 * Converts a set into a vector.
 * This is needed because set does not provide a random access iterator and
 * words can't be accessed by index. Access by index is the most efficient way
 * to pull random words from the dictionary.
 * @param dict_set    The std::set that needs to be converted
 * @return            A vector with the same values as the set.
 */
vector<string> convert_set_to_vector(set<string> dict_set) {
  vector<string> dict_vector;
  for (const auto &word : dict_set)
    dict_vector.push_back(word);

  return dict_vector;
}

/**
 * Handle both the encoding and decoding of the Ceasar Cipher encryption
 * algorithm.
 * The "ASCII Magic Math" details borrowed from Geeks for Geeks Caesar Cipher in
 * Cryptography link can be found in the readme.md
 * @param text      The string to be modified
 * @param key       Integer value for the encryption key (0-25)
 * @param decode    bool True puts the function into decode mode.
 * @return          The resulting string after ceasar cipher applied
 */
string encrypt(string text, int key, bool decode) {
  // Converts the key to decode mode
  if (decode)
    key = 26 - key;

  string result = "";
  for (int i = 0; i < text.length(); i++) {
    if (int(text[i] == 32)) {
      result += text[i];
    } else {
      result += char(int(text[i] + key - 65) % 26 + 65); // ASCII magic math
    }
  }
  return result;
}
