# Introduction
This is an implemenation of the Ceasar Cipher as an introduction to the C++ language and GTest. The code produces two executables for encoding and decoding text. Only upper case characters are supported.

## encoder.exe
This program creates "sentences" of random length between the provided parameters and random words from a list of possible words. It applies the Ceasar Cipher encryption using a random key. The results are either printed to the console or written to a file. 
#### Command Line Parameters
-h | --help    Prints details of the command line options.  
-n | -lines    The number of lines to generate. Defaults to 0 and this is required.  
-l | -length   The minimum number of words per sentence. Defaults to 3.   
-m | -max      The maximum number of words per sentence. Defaults to 25.  
-d | -dict     The path to the word file to create the dictionary. Defaults to words.txt included in the repository.  
-o | -out      Filepath to output the results. Default is standard output.   

## decoder.exe
This program takes a file of sentences encrypted by the ceasar cipher and cracks the encryption. Each line is assumed to have potentially different encryption keys. The output is written to standard out by default or written to a file. The output includes the key that was used for encrypting each line and the decrypted sentence. 

#### Command Line Parameters
-h | --help &emsp;Prints details of the command line options.    
-d | -dict &emsp;The list of possible words that could be in a sentence. Defaults to words.txt included in this repository.  
-i | -in &emsp;&emsp;Path to the file of encrypted sentences.  
-o | -out &emsp;Path to write the results to. Defaults to standard out.  


## decoder-test.exe
Uses GTest for some simple test cases that test the encryption algorithm. Also includes a test case related to the creation of the list of words with the standard ./words.txt

