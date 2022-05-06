#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

typedef struct {
  int size;
  int *arr;
} heap;

int left(int index) {
  return 1 + index * 2;
}

int right(int index) {
  return 2 + index * 2;
}

int parent(int index) {
  return (index - 1) / 2;
}

void max_heapify(heap *heap_p, int index) {
  int left_i = left(index);
  int right_i = right(index);
  int largest;
  if (left_i < (*heap_p).size && (*heap_p).arr[left_i] > (*heap_p).arr[index]) {
    largest = left_i;
  } else {
    largest = index;
  }
  if (right_i < (*heap_p).size && (*heap_p).arr[right_i] > (*heap_p).arr[largest]) {
    largest = right_i;
  }
  if (largest != index) {
    int temp = (*heap_p).arr[index];
    (*heap_p).arr[index] = (*heap_p).arr[largest];
    (*heap_p).arr[largest] = temp;
    max_heapify(heap_p, largest);
  }
}

void build_heap(heap *heap_p) {
  for (int i = (*heap_p).size / 2 - 1; i >= 0; i -= 1) {
    max_heapify(heap_p, i);
  }
}

void heap_sort(int *pointer, int n) {
  heap heap_a = { .size = n, .arr = pointer };
  heap *heap_p = &heap_a;
  build_heap(heap_p);
  for (int i = n - 1; i > 0; i -= 1) {
    int temp = (*heap_p).arr[0];
    (*heap_p).arr[0] = (*heap_p).arr[i];
    (*heap_p).arr[i] = temp;
    (*heap_p).size -= 1;
    max_heapify(heap_p, 0);
  }
}

int main(void) {
  int array[SIZE];
  for (int i = 0; i < SIZE; i += 1) {
    array[i] = rand() % 100;
  }
  for (int i = 0; i < SIZE; i += 1) {
    printf("%3d", array[i]);
  }
  printf("\n");
 /* Do something here to trigger the recursion and modify the array in place. */
  heap_sort(array, SIZE);
  for (int i = 0; i < SIZE; i += 1) {
    printf("%3d", array[i]);
  }
  printf("\n");
}
