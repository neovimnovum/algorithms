#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void sort( unsigned int *arr ) {
  for ( unsigned int i = 1; i < SIZE; i += 1 ) {
    unsigned int key = *(arr + i);
    int j = i - 1;
    while (j >= 0 && key > *(arr + j) ) {
      *(arr + j + 1) = *(arr + j);
      j -= 1;
    }
    arr[j + 1] = key;
  }
  puts("Sorted!");
}

int main(void) {
  unsigned int arr[SIZE];
  for ( unsigned int i = 0; i < SIZE; i += 1 ) {
    arr[i] = i;
    printf("%2d", arr[i]);
  }
  printf("\n");
  sort(arr);
  for ( unsigned int i = 0; i < SIZE; i += 1 ) {
    printf("%2d", arr[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
