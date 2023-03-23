#include <iostream>
#include <vector>

int main(){
  // Shows what maximum index value is
  std::vector<short> temp_vect;
  std::cout << "Max Vector Size: " << temp_vect.max_size() 
    <<  std::endl;

  // Try to populate a large vector
  size_t size = 1;
  std::vector<short> words(size, 0);
  words[size] = 1;
  std::cout << words[size] << std::endl;
  
}