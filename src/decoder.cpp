#include "utils.hpp"
#include "decoder.hpp"
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
  return words;
}

// Validates if a sentence contains real word.
bool validate_sentence(std::set<std::string> dict_set, std::string sentence) {
  auto sentence_vect = parse_sentence(sentence);
  for (std::string word : sentence_vect) {
    if (dict_set.count(word) == 0) {
      return false;
    }
  }
  return true;
}

// "Hacks" the encryption by iterating through all possible keys and checking if
// the resulting sentence.
int break_encrypt(std::set<string> dict_set, std::string &sentence) {
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    std::string decoded_sentence = encrypt(sentence, i, true);
    if (validate_sentence(dict_set, decoded_sentence)) {
      sentence = decoded_sentence;
      return i;
    }
  }
  return -1;
}

/*
  Main driver method that takes in the encoded input and decrypts the input. Once the parameters are defined, the sentences are decrypted with the correct key. If user decides to write to a file, the decrypted sentences are written to file path along with their keys otherwise sentences are written to stdout. 

  * @param word_path  Path to word list
  * @param min_length  Path to encrypted input from the encoder method
   * @param max_length  Path to decrypted output
*/


void read_input_decode(std::string word_path, std::string input_path,
                       std::string dec_out_path) {

  std::set<std::string> dict_set = create_dict(word_path);

  ifstream input_file(input_path);

  if (dec_out_path != "cout") {
    ofstream output_file;
    output_file.open(dec_out_path);

    string line;
    // keeps reading lines while there is still a next line
    while (getline(input_file, line)) {
      output_file << "Key: " << break_encrypt(dict_set, line);
      output_file << " Plaintext: " << line << endl;
    }

    if (input_file.eof()) {

      // closes both files
      input_file.close();
      output_file.close();
    } else {
      string line;
      // keeps reading lines while there is still a next line
      while (getline(input_file, line)) {
        cout << "Key: " << break_encrypt(dict_set, line);
        cout << " Plaintext: " << line << endl;
      }

      if (input_file.eof()) {
        input_file.close();
      }
    }
  }
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