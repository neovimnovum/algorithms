#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 15
#define M_SIZE 32
#define LOG_M 5
#define WORD_SIZE 32
#define ALPHA (((rand() % (M_SIZE / 2))) * 2 + 1)

typedef struct node {
  int value;
  struct node *prev;
  struct node *next;
} node;

typedef struct {
  node *array[M_SIZE];
} ll_table;

typedef struct {
  int array[M_SIZE];
} lp_table;

unsigned int hash(int key) {
  return ((unsigned int)key * ALPHA) >> (WORD_SIZE - 5);
}

int probe(int key, int pnum) {
  return hash(key) + pnum;
}

node *ll_get(ll_table *table, int key) {
  node *ele = table->array[hash(key)];
  if (ele) {
    printf("ele next %p, ele prev %p\n", ele->next, ele->prev);
  }
  while (ele != NULL) {
    if (ele->value == key) {
      return ele;
    }
    ele = ele->next;
  }
  return NULL;
}

void ll_set(ll_table *table, node *ele) {
  printf("\nSet: ele val %d\n", ele->value);
  int index = hash(ele->value);
  printf("Using index %d", index);
  if (table->array[index]) {
    ele->next = table->array[index];
  }
  table->array[index] = ele;
  if (ele->next) {
    printf("ele next pointer = %p\n", ele->next);
    ele->next->prev = ele;
    printf("ele value: %d , ele next value %d\n", ele->value, ele->next->value);
    printf("ele prev pointer after connection = %p\n", (ele->next)->prev);
  }
}

void lp_get(lp_table *table, int array_size, int key) {
}

void lp_set(lp_table *table) {

}

bool ll_twosum(int *array, int arraySize, int target) {
  ll_table cache = { .array = {NULL} };
  for (int i = 0; i < arraySize; i += 1) {
    node *complement = ll_get(&cache, array[i]);
    if (complement) {
      printf("twosum! Second complement is %d.", complement->value);
      return true;
    }
    node *ele = malloc(sizeof *ele);
    ele->value = target - array[i];
    ele->prev = (node*)NULL;
    ele->next = (node*)NULL;
    ll_set(&cache, ele);
    printf("After loop %d, first ele of pointer is %p, same as %p\n", i, cache.array[0], ele);
  }
  printf("No twoSum.");
  return false;
}

void lp_test(void) {

}

int main (void) {
  int array[SIZE] = { 34, 5, 19, 33, 01, 334, 22, 40, 9776, 889, 23, 3, 1, 88, 21 };
  ll_twosum(array, SIZE, 55);
  ll_twosum(array, SIZE, 358743);
  return EXIT_SUCCESS;
}
