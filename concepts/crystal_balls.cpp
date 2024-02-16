// Implementing a search problem without using linear search
// Given two crystal balls that will break if dropped from high enough distance
// Determine the exact spot in which it will break in the most optimized way
// Jumping a square root amount of times
// O(sqrt(N))
#include <cmath>
#include <iostream>
#include <vector>

int crystal(std::vector<bool> *breaks) {
  const size_t jump_dist = std::floor(std::sqrt((*breaks).size()));
  std::cout << jump_dist << std::endl;
  std::cout << "Break size is " << (*breaks).size() << std::endl;
  size_t i = jump_dist; // i is used here to be referenced throughout
                        // Keep jumping forward by jump distance amount until a
                        // position is found where the crystal ball breaks
  for (; i < (*breaks).size(); i += jump_dist) {
    if ((*breaks)[i] == true) {
      std::cout << "Breaks at " << i << " walk back.." << std::endl;
      break;
    }
  }
  // The ball broke now the exact spot needs to be found
  i -= jump_dist;
  std::cout << "Starting at " << i << std::endl;
  for (size_t j = 0; j <= jump_dist && i < (*breaks).size(); j++, i++) {
    if ((*breaks)[i]) {
      std::cout << "Broke at " << i << std::endl;
    }
  }

  return i;
}
int main() {
  std::cout << "Hello world\n";
  std::vector<bool> breaks = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              1, 0, 0, 0, 1, 0, 1, 0, 0, 1};
  crystal(&breaks);
}
