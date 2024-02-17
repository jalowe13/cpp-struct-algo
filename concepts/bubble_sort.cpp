#include <iostream>
#include <vector>

void display_iteration(std::vector<int> *arr) {
  std::vector<int> &arr_p = *arr;
  const size_t arr_len = arr_p.size();
  std::cout << "[";
  for (size_t i = 0; i < arr_len; i++) {
    std::cout << arr_p[i] << (i != arr_len - 1 ? "," : "]\n");
  }
}

// Xi<=Xi+1
bool bubble_sort(std::vector<int> *arr) {
  std::vector<int> &arr_p = *arr;
  for (size_t j = 0; j < arr_p.size(); j++) {
    for (size_t i = 0; i < arr_p.size() - 1; i++) {
      if (arr_p[i] >= arr_p[i + 1]) {
        std::swap(arr_p[i], arr_p[i + 1]);
      }
    }
  }
  return true;
}

int main() {
  std::cout << "Welcome to Bubble Sort\n";
  std::cout << "Test 1\n";
  std::vector<int> unsorted_vector = {5, 3, 7, 1, 9, 4, 2, 8, 6};
  display_iteration(&unsorted_vector);
  bubble_sort(&unsorted_vector);
  display_iteration(&unsorted_vector);
  std::cout << "Test 2\n";
  unsorted_vector = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21, 62, 27, 90,
                     59, 63, 26, 40, 26, 72, 36, 11, 68, 67, 29, 82, 30,
                     62, 23, 67, 35, 29, 2,  22, 58, 69, 67, 93, 56, 11,
                     42, 29, 73, 21, 19, 84, 37, 98, 24, 15, 70};
  display_iteration(&unsorted_vector);
  bubble_sort(&unsorted_vector);
  display_iteration(&unsorted_vector);
  std::cout << "Test 3\n";
  unsorted_vector = {-83, 86, -77, 15,  -93, 35,  86,  -92, 49,  21,
                     -62, 27, 90,  -59, 63,  26,  -40, 26,  72,  36,
                     -11, 68, -67, 29,  82,  -30, 62,  23,  -67, 35,
                     29,  -2, 22,  58,  -69, 67,  93,  -56, 11,  42,
                     -29, 73, 21,  -19, 84,  37,  -98, 24,  15,  70};
  display_iteration(&unsorted_vector);
  bubble_sort(&unsorted_vector);
  display_iteration(&unsorted_vector);
}
