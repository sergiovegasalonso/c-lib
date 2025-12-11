#include "singly_linked_list/src/singly_linked_list.h"
#include <stdio.h>

int main() {
  Node *head = NULL;

  // Add 10 elements to the list
  printf("Inserting 10 elements...\n");
  for (int i = 1; i <= 10; i++) {
    insert_at_end(&head, i * 10);
  }
  printf("Initial list: ");
  print_list(head);
  printf("\n");

  // Delete one by key
  int key_to_delete = 50;
  printf("Deleting node with key: %d\n", key_to_delete);
  delete_node_by_key(&head, key_to_delete);
  printf("List after deleting key %d: ", key_to_delete);
  print_list(head);
  printf("\n");

  // Delete one by position
  int position_to_delete = 2;
  printf("Deleting node at position: %d\n", position_to_delete);
  delete_node_by_position(&head, position_to_delete);
  printf("List after deleting node at position %d: ", position_to_delete);
  print_list(head);
  printf("\n");

  // Free the remaining list
  printf("Freeing the list...\n");
  Node *current = head;
  Node *next_node;
  while (current != NULL) {
    next_node = current->next;
    free(current);
    current = next_node;
  }
  head = NULL;
  printf("List freed.\n");

  return 0;
}