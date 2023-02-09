// #include <iostream>
// #include <string>
// using namespace std;

// //generated from chatgpt 

// string encryptCaesarCipher(string plaintext, int key) {
//     string ciphertext = "";
//     for (int i = 0; i < plaintext.length(); i++) {
//         char c = plaintext[i];
//         if (isalpha(c)) {
//             char offset = isupper(c) ? 'A' : 'a';
//             c = (c - offset + key) % 26 + offset;
//         }
//         ciphertext += c;
//     }
//     return ciphertext;
// }

// string decryptCaesarCipher(string ciphertext, int key) {
//     string plaintext = "";
//     for (int i = 0; i < ciphertext.length(); i++) {
//         char c = ciphertext[i];
//         if (isalpha(c)) {
//             char offset = isupper(c) ? 'A' : 'a';
//             c = (c - offset - key + 26) % 26 + offset;
//         }
//         plaintext += c;
//     }
//     return plaintext;
// }

// int main() {
//     string plaintext;
//     cout << "Enter plaintext: ";
//     getline(cin, plaintext);
//     int key;
//     cout << "Enter key: ";
//     cin >> key;

//     string ciphertext = encryptCaesarCipher(plaintext, key);
//     cout << "Ciphertext: " << ciphertext << endl;

//     string decrypted = decryptCaesarCipher(ciphertext, key);
//     cout << "Decrypted: " << decrypted << endl;

//     return 0;
// }
