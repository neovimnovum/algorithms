#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

unsigned int merge_inversions(unsigned int *lower, unsigned int *mid, unsigned int *upper) {
  unsigned int inversions = 0;
  unsigned int l_length = mid - lower + 1;
  unsigned int left[l_length];
  unsigned int *left_upper = left + (l_length - 1);
  for (unsigned int i = 0; i < l_length; i += 1) {
    *(left + i) = *(lower + i);
  }
  unsigned int *lptr = left;
  unsigned int *rptr = mid + 1;
  while (lptr <= left_upper && rptr <= upper) {
    if (*lptr <= *rptr) {
      *lower = *lptr;
      lptr += 1;
    } else {
      *lower = *rptr;
      rptr += 1;
      inversions += left_upper - left + 1;
    }
    lower += 1;
  }
  while (lptr <= left_upper) {
    *lower = *lptr;
    lptr += 1;
    lower += 1;
  }
  while (rptr <= upper) {
    *lower = *rptr;
    rptr += 1;
    lower += 1;
  }
  return inversions;
}

unsigned int count_inversions(unsigned int *lower, unsigned int *upper) {
  unsigned int inversions = 0;
  printf("Lower:%2d upper:%2d\n", *lower, *upper);
  if (lower < upper) {
    unsigned int *mid = lower + (upper - lower) / 2;
    inversions += count_inversions(lower, mid);
    inversions += count_inversions(mid + 1, upper);
    inversions += merge_inversions(lower, mid, upper);
  }
  return inversions;
}

int main(void) {
  unsigned int arr[SIZE];

  for (unsigned int i = 0, j = SIZE - 1; i < SIZE; i += 1, j -= 1) {
    arr[i] = j;
    printf("%2d", arr[i]);
  }
  printf("\n");
  
  printf("%2d Inversions\n", count_inversions(arr, arr + SIZE - 1));
  for (unsigned int i = 0; i < SIZE; i += 1) {
    printf("%2d", arr[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
