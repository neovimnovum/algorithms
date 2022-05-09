#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

typedef struct stack {
  int size;
  int *top;
  int array[SIZE];
} stack;

typedef struct queue {
  int size;
  int *tail;
  int *head;
  int array[SIZE];
} queue;

void print_array(int *array) {
  printf("Array in stack: ");
  for (int i = 0; i < SIZE; i += 1) {
    printf("%2d", *(array + i));
  }
  printf("\n");
}

void print_stack(stack *s) {
  printf("Stack: ");
  int *pointer = (*s).array;
  while (pointer <= (*s).top) {
    printf("%2d", *pointer);
    pointer += 1;
  }
  printf("\n");
}

bool is_empty(stack *stack) {
  if ((*stack).top < (*stack).array) {
    return true;
  }
  return false;
}

void push(stack *stack, int ele) {
  if ((*stack).top - 1 < (*stack).array + (*stack).size) {
    (*stack).top += 1;
    *((*stack).top) = ele;
  }
  return;
}

int pop(stack *stack) {
  if (!is_empty(stack)) {
    int result = *(*stack).top;
    *(*stack).top = 0;
    (*stack).top -= 1;
    return result;
  }
  return 0;
}

void test_stack(void) {
  stack new_stack = { .size = SIZE, .array = {}, .top = new_stack.array - 1 };
  stack *s = &new_stack;
  push(s, 4);
  push(s, 5);
  push(s, 8);
  print_array(new_stack.array);
  print_stack(s);
  push(s, 3);
  push(s, 2);
  printf("%d\n", *(*s).top);
  printf("Last element: %2d\n", pop(s));
  printf("Last element: %2d\n", pop(s));
  printf("Last element: %2d\n", pop(s));
  printf("Last element: %2d\n", pop(s));
  printf("Last element: %2d\n", pop(s));
  printf("Last element: %2d\n", pop(s));
  printf("Last element: %2d\n", pop(s));
  printf("Last element: %2d\n", pop(s));
  printf("Last element: %2d\n", pop(s));
  print_stack(s);
  print_array(new_stack.array);
  push(s, 33);
  print_stack(s);
  print_array(new_stack.array);
  return;
}

void enqueue(queue *s) {

}

int dequeue(queue *s) {
  if (s->head != s->tail) {
    int result = *s->head;
    *s->head = 0;
    s->head -= 1;
    if (s->head <)
    return result;
  }
  return 0;
}

void test_queue(int size) {
  queue new_queue;
  return;
}

int main(void) {
  test_stack();
  return EXIT_SUCCESS;
}
