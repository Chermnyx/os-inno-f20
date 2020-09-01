#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node* next;
} Node;

void print_list(Node** list) {
  Node* current = *list;
  printf("[");
  while (current) {
    printf("%d", current->val);
    current = current->next;
    if (current) printf(" ");
  }
  printf("]\n");
}

Node* insert_node(Node** list, int i, int val) {
  size_t j;
  Node* prev_node = *list;
  for (j = 1; j < i; ++j) {
    prev_node = prev_node->next;
  }

  Node* new = malloc(sizeof(Node));
  new->val = val;
  new->next = 0;

  if (prev_node) {
    Node* prev_next = prev_node->next;
    new->next = prev_next;
    prev_node->next = new;
  } else {
    *list = new;
  }

  return new;
}

void delete_node(Node** list, int i) {
  size_t j;
  Node* prev_node = *list;
  for (j = 1; j < i; ++j) {
    prev_node = prev_node->next;
  }

  if (i == 0) {
    Node* removed = *list;
    *list = removed->next;
    free(removed);
  } else {
    Node* removed = prev_node->next;
    prev_node->next = (removed ? removed->next : 0);
    free(removed);
  }
}

int main(int argc, char const* argv[]) {
  Node* head = 0;
  insert_node(&head, 0, 0);
  insert_node(&head, 1, 1);
  insert_node(&head, 2, 2);
  insert_node(&head, 1, 11);
  print_list(&head);
  delete_node(&head, 2);
  print_list(&head);
  delete_node(&head, 0);
  print_list(&head);
  return 0;
}
