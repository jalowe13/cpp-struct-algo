#include <cmath>
#include <iostream>
#include <vector>

std::pair<int, int> binary_search(std::vector<int> *arr, int low, int high,
                                  int n) {
  std::cout << "Start Search" << std::endl;
  while (low < high) {
    int midpoint = std::floor(low + ((high - low) / 2));
    int value = (*arr)[midpoint];
    if (value == n) {
      return {value, midpoint};
    } else if (value > n) {
      high = midpoint;
    } else {
      low = midpoint + 1;
    }
  }
  std::cout << "Not found\n";
  return {-1, -1};
}
int main() {
  std::cout << "Binary Search" << std::endl;
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << "Searching for 3 in Vector using binary search\n";
  std::pair<int, int> result = binary_search(&arr, 0, arr.size(), 3);
  std::cout << "Found " << result.first << " at " << result.second << std::endl;
}
