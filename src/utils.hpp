#pragma once
#include <string>
#include <set>
#include <vector>

using namespace std;

// Constants
const int ALPHABET_SIZE = 26;
const int ALPHABET_RANGE = 25;
const string SPECIAL_CHARACTERS = " '@#$%^&*";


// Functions 
// Note: GKT added extern

extern set<string> create_dict(string file_path);
extern vector<string> convert_set_to_vector(set<string> dict_set);
extern string encrypt(string text, int key, bool decode = false);