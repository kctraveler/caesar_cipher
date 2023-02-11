#include "utils.hpp"
#include <fstream>
#include <iostream>
#include <vector>

/*
* Outputs help text for using the CLI
* @param prgname  The name of the executable called
//*/
void help(const char *prgname) {
  fprintf(stderr, "Help for %s\n", prgname);
  fprintf(stderr, "\t-h | --help\t\tWrite this help information\n");
  fprintf(stderr,
          "\t-d | -dict\t\tPath to dictionary file\t\t\tDefault ./words.txt\n");
  fprintf(stderr, "\t-i | -in\t\tPath to input file\t\t\tDefault stdin\n");
  fprintf(stderr,
          "    -o | -out\t\tPath to output results.\t\t\tDefault stdout\n");
}

// Parses sentence into a vector or words.
// Potential future issue is non space special characters are in the input.
std::vector<std::string> parse_sentence(std::string sentence) {
  std::vector<std::string> words = {""};
  int word_index = 0;
  for (int i = 0; i < sentence.length(); i++) {
    if (int(sentence[i]) == 32) {
      word_index += 1;
      words.push_back("");
    } else {
      words[word_index] += sentence[i];
    }
  }
  words.erase(words.begin()); // remove "Encrypted: from vector"
  return words;
}

// Validates if a sentene contains real word.
bool validate_sentence(std::set<std::string> dict_set, std::string sentence) {
  int valid_word_count = 0;
  auto sentence_vect = parse_sentence(sentence);
  for (std::string word : sentence_vect) {
    // cout << word << endl;
    if (dict_set.count(word) == 0) {
      return false;
    }
  }
  return true;
}

// "Hacks" the encryption by iterating through all possible keys and checking if
// the resulting sentence.
std::string break_encrypt(std::set<string> dict_set, std::string sentence) {
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    std::string decoded_sentence = encrypt(sentence, i, true);
    if (validate_sentence(dict_set, decoded_sentence)) {
      return decoded_sentence;
    }
  }
  return sentence;
}

/*
 Reads input file, line by line.
*/
void readInput(std::string input_path) {
  ifstream file;
  file.open(input_path);
  if (!file) {
    cout << "Error opening file! Try again." << endl;
    return;
  }

  string line;
  while (getline(file, line)) {
    cout << line << endl;
  }

  // file stays open for us to decode

  //  file.close();
}

/* decoder method must
1) open input file/read stdio
2) process line by line
3) use the caesar cipher code to get the key
4) return the key and decoded text
5) REPEAT FOR EACH LINE
*/

int get_random_key() {
  int key = rand() % ALPHABET_RANGE;
  return key;
}

void read_input_decode(std::string word_path, std::string input_path,
                       std::string dec_out_path) {
  // readInput(input_path);

  string line;
  ifstream input_file(input_path);
  ofstream file2;
  std::set<std::string> dict_set = create_dict(word_path);
  file2.open(dec_out_path);

  // keeps reading lines while there is still a next line
  while (getline(input_file, line)) {
    // int key = get_random_key();
    // writes input file to output
    // STILL HAVE TO FACTOR IN DECRYPTION
    // doesn't work but something like this maybe?
    // int key = get_random_key();
    // auto sentence = line;
    // encrypt(sentence, key, true);
    // cout << "Decrypted: " << sentence << endl;

    cout << break_encrypt(dict_set, line) << endl;

    // writes decoded line to output file
    // file2 << line << endl;
  }

  if (input_file.eof()) {
    cout << "End of input file reached, both files closed." << endl;

    // closes both files
    input_file.close();
    file2.close();
  }

  // file stays open

  // write a method that reads one line and then decodes and then we run a
  // loop to execute method for each line of input

  /*
      input file stays open
      line by line each input file is read
          when it's read its decoded
          once the line is decoded it is written to output file
      close both files
      input stays the same
      output file now has decoded text

  */
}

int main(int argc, char *argv[]) {

  std::string dict_path = "./words.txt"; // filepath to the word list/dictionary
  std::string dec_out_path = "cout";     // filepath to write the decoded output
  std::string input_path = "./result.txt"; // filepath to the input

  for (int i = 1; i < argc;) {
#define check_index(i, str)                                                    \
  if ((i) >= argc) {                                                           \
    fprintf(stderr, "Missing 2nd argument for %s\n", str);                     \
    return 1;                                                                  \
  }

    std::string key = argv[i++];
    if (key == "-h" || key == "--help") {
      help(argv[0]);
      return 0;
    } else if (key == "-i" || key == "-input") {
      check_index(i, "-i|-input");
      input_path = argv[i];
      i++;
    } else if (key == "-d" || key == "-dict") {
      check_index(i, "-d|-dict");
      dict_path = argv[i];
      i++;
    } else if (key == "-o" || key == "-output") {
      check_index(i, "-o|-output");
      dec_out_path = argv[i];
      i++;
    } else {
      fprintf(stderr, "Unknown options %s\n", key.c_str());
      help(argv[0]);
      return 1;
    }
  }

  read_input_decode(dict_path, input_path, dec_out_path);
  return 0;
}