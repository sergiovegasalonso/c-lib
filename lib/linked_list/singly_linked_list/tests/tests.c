#include "../src/singly_linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_create_node() {
  printf("Testing create_node...");
  Node *node = create_node(10);
  assert(node != NULL);
  assert(node->data == 10);
  assert(node->next == NULL);
  free(node);
  printf("PASSED\n");
}

void test_insert_at_beginning() {
  printf("Testing insert_at_beginning...");
  Node *head = NULL;
  insert_at_beginning(&head, 10);
  assert(head != NULL);
  assert(head->data == 10);
  insert_at_beginning(&head, 20);
  assert(head->data == 20);
  assert(head->next->data == 10);
  assert(head->next->next == NULL);
  delete_from_end(&head);
  delete_from_end(&head);
  printf("PASSED\n");
}

void test_insert_at_end() {
  printf("Testing insert_at_end...");
  Node *head = NULL;
  insert_at_end(&head, 10);
  assert(head != NULL);
  assert(head->data == 10);
  insert_at_end(&head, 20);
  assert(head->next != NULL);
  assert(head->next->data == 20);
  assert(head->next->next == NULL);
  delete_from_end(&head);
  delete_from_end(&head);
  printf("PASSED\n");
}

void test_insert_at_position() {
  printf("Testing insert_at_position...");
  Node *head = NULL;
  insert_at_end(&head, 10);
  insert_at_end(&head, 30);
  insert_at_position(&head, 20, 1);
  assert(head->next->data == 20);
  insert_at_position(&head, 5, 0);
  assert(head->data == 5);
  insert_at_position(&head, 40, 4);
  Node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;
  assert(temp->data == 40);

  while (head != NULL) {
    delete_from_beginning(&head);
  }
  printf("PASSED\n");
}

void test_delete_from_beginning() {
  printf("Testing delete_from_beginning...");
  Node *head = NULL;
  insert_at_end(&head, 10);
  insert_at_end(&head, 20);
  delete_from_beginning(&head);
  assert(head != NULL);
  assert(head->data == 20);
  delete_from_beginning(&head);
  assert(head == NULL);
  printf("PASSED\n");
}

void test_delete_from_end() {
  printf("Testing delete_from_end...");
  Node *head = NULL;
  insert_at_end(&head, 10);
  insert_at_end(&head, 20);
  delete_from_end(&head);
  assert(head != NULL);
  assert(head->next == NULL);
  assert(head->data == 10);
  delete_from_end(&head);
  assert(head == NULL);
  printf("PASSED\n");
}

void test_delete_node_by_position() {
  printf("Testing delete_node_by_position...");
  Node *head = NULL;
  insert_at_end(&head, 10);
  insert_at_end(&head, 20);
  insert_at_end(&head, 30);
  insert_at_end(&head, 40);

  delete_node_by_position(&head, 2);
  assert(head->next->next->data == 40);

  delete_node_by_position(&head, 0);
  assert(head->data == 20);

  delete_node_by_position(&head, 1);
  assert(head->data == 20);
  assert(head->next == NULL);

  delete_from_beginning(&head);
  assert(head == NULL);
  printf("PASSED\n");
}

void test_delete_node_by_key() {
  printf("Testing delete_node_by_key...");
  Node *head = NULL;
  insert_at_end(&head, 10);
  insert_at_end(&head, 20);
  insert_at_end(&head, 30);
  insert_at_end(&head, 40);

  delete_node_by_key(&head, 30);
  assert(head->next->next->data == 40);

  delete_node_by_key(&head, 10);
  assert(head->data == 20);

  delete_node_by_key(&head, 40);
  assert(head->data == 20);
  assert(head->next == NULL);

  delete_from_beginning(&head);
  assert(head == NULL);
  printf("PASSED\n");
}

int main() {
  printf("Running Singly Linked List Tests...\n");
  test_create_node();
  test_insert_at_beginning();
  test_insert_at_end();
  test_insert_at_position();
  test_delete_from_beginning();
  test_delete_from_end();
  test_delete_node_by_position();
  test_delete_node_by_key();
  printf("All tests passed successfully!\n");
  return 0;
}
