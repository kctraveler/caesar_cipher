#include "BloomFilter.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include "openssl/sha.h"

// Populates bloom filter with each line of specified file path. 
// Returns the number of conflicts (assumption that input is unique list)
int populate_filter(std::string file_path, BloomFilter filter) {
  int num_conflicts = 0;
  std::fstream words_file;
  words_file.open(file_path);
  if (words_file.is_open()) {
    std::string line;
    while (getline(words_file, line)) {
      if (filter.find(line)) {
        num_conflicts +=1;
        filter.add(line);
        printf("%s \n", &*line.begin());
      }else {
        filter.add(line);
      }
    }
  }
  words_file.close();
  return num_conflicts;
}

int main(int argc, char *argv[]){
  std::string file_path = "./words.txt";
  int bits = 100000000; //m
  int num_hash_functions = 1; //k

  for (int i = 1; i < argc;) {
#define check_index(i, str)                                                    \
  if ((i) >= argc) {                                                           \
    fprintf(stderr, "Missing 2nd argument for %s\n", str);                     \
    return 1;                                                                  \
  }

    std::string key = argv[i++];
    if (key == "-b" || key == "--bits") {
      check_index(i, "-b,|--bits");
      bits = atoi(argv[i]);
      i++;
    } else if (key == "-h" || key == "--hashf") {
      check_index(i, "-h|--hashf");
      num_hash_functions = atoi(argv[i]);
      i++;
    } else if (key == "-d" || key == "--dict") {
      check_index(i, "-d|-dict");
      file_path = argv[i];
      i++;
    } else {
      fprintf(stderr, "Unknown options %s\n", key.c_str());
      return 1;
    }
  }
   
  BloomFilter filter(bits, num_hash_functions);
  std::cout << populate_filter(file_path, filter);
  
  return 0;
}