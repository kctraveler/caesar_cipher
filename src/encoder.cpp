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
  fprintf(stderr, "\t-n | -lines\t\tNumber of lines to generate\t\tRequired\n");
  fprintf(stderr, "\t-l | -length\tMinimum words per line.\t\t\tDefault 3\n");
  fprintf(stderr, "\t-m | -max\t\tMaximum words per line.\t\t\tDefault 25\n");
  fprintf(stderr,
          "\t-d | -dict\t\tPath to dictionary file\t\t\tDefault ./words.txt\n");
  fprintf(stderr,
          "    -o | -out\t\tPath to output results.\t\t\tDefault stdout\n");
}

/**
 * Generates a "sentence" of random length between the provided parameters using
 * randomly selected words from the dictionary.
 * @param word_vector The vector containing the words that can be used in the
 * sentence
 * @param min_length  The minimum length of the sentence
 * @param max_length  The maximum length of the sentence
 * @return            The randomly generated sentence
 */
std::string generate_sentence(std::vector<std::string> word_vector,
                              int min_length, int max_length) {
  int sentence_length = min_length + (rand() % (max_length - min_length));
  std::string sentence = "";
  for (int i = 0; i < sentence_length; i++) {
    auto rand_index = rand() % word_vector.size();
    sentence += word_vector[rand_index] + " ";
  }
  sentence.pop_back(); // remove trailing space
  return sentence;
}

/**
 * Used to generate keys for encrypting sentences.
 * @return        A random integer between 0 and 25 to serve as the key for
 * encryption
 */
int get_random_key() {
  int key = rand() % ALPHABET_RANGE;
  return key;
}

void generate_output(int num_lines, int min_length, int max_length,
                     std::string word_path, std::string out_path) {
  srand(time(NULL));
  std::set<std::string> word_set = create_dict(word_path);
  std::vector<std::string> word_vector = convert_set_to_vector(word_set);

  if (out_path != "cout") {
    ofstream out_file(out_path);
    while (out_file.is_open()) {
      for (int i = 0; i < num_lines; i++) {

        int key = get_random_key();
        auto sentence = generate_sentence(word_vector, min_length, max_length);
        sentence = encrypt(sentence, key);
        out_file << sentence << std::endl;
      }
      out_file.close();
    }
  } else {
    for (int i = 0; i < num_lines; i++) {

      int key = get_random_key();
      auto sentence = generate_sentence(word_vector, min_length, max_length);
      sentence = encrypt(sentence, key);
      cout << sentence << std::endl;
    }
  }
}

int main(int argc, char *argv[]) {

  int lines = 0;       // number of lines to generate
  int min_length = 3;  // minimum number of words to generate per line
  int max_length = 25; // maximum number of words to generate per line
  std::string dict_path = "./words.txt"; // filepath to the word list/dictionary
  std::string out_path = "cout";         // filepath to write the output

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
    } else if (key == "-n" || key == "-lines") {
      check_index(i, "-n|-lines");
      if (isdigit(*argv[i]))
        lines = atoi(argv[i]);
      i++;
    } else if (key == "-l" || key == "-length") {
      check_index(i, "-l|-length");
      if (isdigit(*argv[i]))
        min_length = atoi(argv[i]);
      i++;
    } else if (key == "-m" || key == "-max") {
      check_index(i, "-m|-max");
      if (isdigit(*argv[i]))
        max_length = atoi(argv[i]);
      i++;
    } else if (key == "-d" || key == "-dict") {
      check_index(i, "-d|-dict");
      dict_path = argv[i];
      i++;
    } else if (key == "-o" || key == "-output") {
      check_index(i, "-o|-output");
      out_path = argv[i];
      i++;
    } else {
      fprintf(stderr, "Unknown options %s\n", key.c_str());
      help(argv[0]);
      return 1;
    }
  }
  std::cout << encrypt("HELLO WORLD", 3, false) << std::endl;
  generate_output(lines, min_length, max_length, dict_path, out_path);

  return 0;
}