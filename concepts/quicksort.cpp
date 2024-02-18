#include <iostream>
#include <vector>

// Pivot point Jacob Lowe
// Everything smaller than pivot is on left side, everything bigger
// on right side
// First pivot in the middle - Weak sort
// low <= Px < high
// Continue spliting between pivots
// low <= Px+1 < Px
// Px <= Px+1 < high
// low <= Px+2 < Px+1
// Px+1 <= Px+2 < high
// Array of nothing or element of 1 completely sorts the array
// O(nlogn) runtime
// reverse sorted array would be the worst runtime for this
// O(n^2)
void print_vec(std::vector<int> *p_test_vector) {
  const size_t vec_len = (*p_test_vector).size();
  std::cout << "[";
  for (size_t i = 0; i < p_test_vector->size(); i++) {
    std::cout << (*p_test_vector)[i] << (i != vec_len - 1 ? "," : "]\n");
  }
}
size_t partition(std::vector<int> *p_test_vector, size_t low, size_t high) {
  std::vector<int> &test_vector = (*p_test_vector);
  int pivot = test_vector[high];
  size_t idx = low - 1;
  for (size_t i = low; i < high; i++) {
    if (test_vector[i] <= pivot) {
      idx++;
      // Swap
      const int tmp = test_vector[i];
      test_vector[i] = test_vector[idx];
      test_vector[idx] = tmp;
    }
  }
  idx++;
  test_vector[high] = test_vector[idx];
  test_vector[idx] = pivot;
  print_vec(p_test_vector);
  return idx;
}
void quicksort(std::vector<int> *test_vector, size_t low, size_t high) {
  if (low >= high) {
    return;
  }
  const int pivot = partition(test_vector, low, high);
  quicksort(test_vector, low, pivot - 1);
  quicksort(test_vector, pivot + 1, high);
}

int main() {
  std::vector<int> test_vector = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
  std::vector<int> test_vector2 = {5, 3, 1, 2, 6, 4, 8, 7, 9, 10};
  quicksort(&test_vector, 0, test_vector.size() - 1);
  quicksort(&test_vector2, 0, test_vector2.size() - 1);
}
