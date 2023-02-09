#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <cctype>
#include <algorithm>

using namespace std;

//START NOTES FROM CLASS
//map char char ,cc
//auto alphabet = string 'ABCDE...'
//auto shift = 3;

/*

for (auto i = 0; i < alphabet.length(); i++){
acc[alphabet[i]]
 alphabet[(i+shift) % alphabet.length()]}

for (const auto item : mcc {
cout << item.first<< : " << item.second"
})


*/
// END NOTES FROM CLASS



//read lines -> create dictionary of words 

//n - number of lines to generate
// d - location of words 
// l - minimum word length
// o - output location
// w - max words per line
void encoder (string o, int n, int w, string d = "words", int l = 3) {
  	//created a list of words in terminal using 'aspell -l en dump master > words.txt'

     //stores words
  set<string> wordList;
  string word;
  
  //reading word list
  string line;
  string special_characters = "'@#$%^&*";

  ifstream file("words.txt");
  if (file.is_open()) {
    while (getline(file, line)) {
  while (file >> word) {
        //filtering out words with special characters and adding words to set
    size_t found = word.find_first_of(special_characters);
     if (found != string::npos) {
        wordList.erase(word);
      } else { wordList.insert(word);
       }
      //filtering out words with less than 3 char
        if (word.length() < 3){
          wordList.erase(word);
      }
    }
  }
    file.close();
} else {
    cout << "Unable to open file\n";
}
  
   // for (string word: wordList) {
   // //capitalizes words in set
   //       transform(word.begin(), word.end(), word.begin(), ::toupper);
   //       //cout << word << "\n" ;
   // } 
  // cout << "There are " << wordList.size() << " words in the word list" << endl;



//populate vector from wordList 
vector<string> updatedWords;
  for (const auto &word: wordList){
    updatedWords.push_back(word);
  }


  //generates random number
  srand(time(NULL));
  string sentence ="";

  //generates sentences using the updated dictionary and user input (n and w)
  for (int i = 0; i < n; i++) {
      //some code from chatGPT
  for (int i = 0; i < w; i++){
    for (string& word : updatedWords) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
      }
    int random_word_index = rand() % updatedWords.size();
    sentence += updatedWords[random_word_index] + " ";
  }

    }

   cout << sentence << endl;
    cout << " " << endl;


}

// void decoder (int n,  string d, string o) {
//   // cout << n << endl;
//   // cout << d << endl;
//   // cout << o << endl;

//   //use set of strings for datasetc
// }


int main(int argc, char **argv) {

  

  //user input for encoder
  string outputFileName;
  int nLines;
  int nWords;
   cout << "Enter the name you wish to name your output file:";
  cin >> outputFileName;
  cout << " " << endl;
  cout << "Enter the number of lines you wish to generate:";
  cin >> nLines;
  cout << " " << endl;
  cout << "Enter the maximum number of words in a sentence :";
  cin >> nWords;
  cout << " " << endl;
  encoder(outputFileName, nLines, nWords);

	return 0;
}