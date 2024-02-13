#include <iostream>
bool linear_search(int* haystack, int needle){
  for (int i = 0; i < sizeof(haystack); i++){
    if (haystack[i] == needle){
      std::cout << "Found the needle\n";
      return true;
    }
  }
  return false;
}

int main(){
  // Initialize an array
  std::cout << "Finding needle in the haystack\n";
  int haystack[10] = {0,4,5,6,2,3,5,6,7,7};
  int* haystack_p = haystack;
  linear_search(haystack_p,6);
}
