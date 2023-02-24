#pragma once
#include <iostream>
#include <string>
#include "boost/dynamic_bitset.hpp"

class BloomFilter {
  private:
    int m; // size of bitset
    int k; // number of hash functions 
    boost::dynamic_bitset<> filter;
    // hash funcs not a member of the class, need to understand C++ OOP better. Issues with seperating the implementation from definition.

  public:
    BloomFilter(size_t m, int k);
    void add(std::string str);
    bool find(std::string str);
};