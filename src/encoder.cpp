#include "utils.hpp"
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
  srand(time(NULL)); // TODO #ifdef to standardize seed for testing?
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
 * @return        A random integer between 0 and 25 to serve as the key for encryption
 */
int get_random_key() {
  srand(time(NULL));
  int key = rand() % ALPHABET_RANGE;
  return key;
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

    std::string key(argv[i++]);
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

  // create dictionary in the appropriate data structures
  std::set<std::string> word_set = create_dict(dict_path);
  std::vector<std::string> word_vector = convert_set_to_vector(word_set);

  // temporary code for testing single sentence with known key.
  auto sentence = generate_sentence(word_vector, min_length, max_length);
  std::cout << "Input:\t" << sentence << std::endl;
  sentence = encrypt(sentence, 3);
  std::cout << "Encrypted:\t" << sentence << std::endl;
  sentence = encrypt(sentence, 3, true);
  std::cout << "Decrypted:\t" << sentence << std::endl;

  for(int i = 0; i < lines;  i++){
    if (out_path != "cout")
  }

  return 0;
}