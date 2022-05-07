#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void print_array(int *array, unsigned int size) {
  for (int i = 0; i < size; i += 1) {
    printf("%2d", *(array + i));
  }
  printf("\n");
}

int *partition(int *i, int *pivot) {
  i -= 1;
  for (int *j = i + 1; j <= pivot; j += 1) {
    if (*j <= *pivot) {
      i += 1;
      int temp = *i;
      *i = *j;
      *j = temp;
    }
  }
  return i;
}

void quick_sort(int *arr, int *end) {
  if (end <= arr) {
    return;
  }
  int *mid = partition(arr, end);
  quick_sort(arr, mid - 1);
  quick_sort(mid + 1, end);
  return;
}

int main(void) {
  int arr[SIZE] = { 2, 8, 7, 1, 3, 5, 6, 4 };
  print_array(arr, SIZE);
  quick_sort(arr, arr + SIZE - 1);
  print_array(arr, SIZE);
  return EXIT_SUCCESS;
}
