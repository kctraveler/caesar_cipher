//This is the primary file for the implementaiton of the bloom filter.
//Need to decide if this should be a class or just functions. 
//Need to see assignment requirements. If we create a class for the data structure, should that class provide the methods
// for running the experiments or does that need to be  split into something seperate. 

#include "BloomFilter.hpp"
#include "boost/dynamic_bitset.hpp"
#include <functional>
#include "boost/functional/hash.hpp"
#include <cmath>

// Need to figure out if this should be a member of the class. 
// Had difficulty when seperateing the definition and implementation
// This is the array of hash functions to iterate within range k.
std::function<std::size_t(std::string&)> fun_arr[] = {
  [](std::string& str) {
    size_t hash = std::hash<std::string>{}(str);
    return hash;
  },
  [](std::string& str){
    boost::hash<std::string> boost_hash;
    return boost_hash(str);
  },
  //DJB2 Hash Algorithm 
  [](std::string& str) { 
    size_t hash = 5381;
    for (auto c : str) {
        hash = (hash << 5) + hash + c; /* hash * 33 + c */
    }
    return hash;
},
// sdbm
[](std::string& str) { 
    size_t hash = 0;
    for (auto c : str) {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}
  
  // Addl hash functions go here
};

// Constructor for bloom filter p
BloomFilter::BloomFilter(size_t m, int k): m(m), k(k), n(0){
  filter = boost::dynamic_bitset<>(this->m);
};

void BloomFilter::add(std::string str){
  // apply all hash functions up to k not exceeding number of hash funcs
  int num_hash_funcs = sizeof(fun_arr)/sizeof(fun_arr[0]);
  for(int i = 0; i < k && i < num_hash_funcs ; i++ ){
    auto hash_val = fun_arr[i](str);
    filter[hash_val % this->m] = true;
  }
  this->n += 1;
}

float BloomFilter::find(std::string str){
  int num_hash_funcs = sizeof(fun_arr)/sizeof(fun_arr[0]);
  for(int i = 0; i < k && i < num_hash_funcs ; i++ ){
    auto hash_val = fun_arr[i](str);
    if(!filter[hash_val % this->m])
      return 0;
  }
  float probability  = pow((1.0 - pow((1.0 - 1.0/this->m),(this->k * this->n))), this->k);
  return probability;
}