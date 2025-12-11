#include "singly_linked_list.h"

/**
 * @brief Creates a new node.
 * @param data The data to store in the new node.
 * @return A pointer to the newly created node.
 */
Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    perror("Unable to allocate memory for new node");
    exit(EXIT_FAILURE);
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

/**
 * @brief Inserts a new node at the beginning of the list.
 * @param head_ref A pointer to the head of the list.
 * @param new_data The data for the new node.
 */
void insert_at_beginning(Node **head_ref, int new_data) {
  Node *new_node = create_node(new_data);
  new_node->next = *head_ref;
  *head_ref = new_node;
}

/**
 * @brief Inserts a new node at the end of the list.
 * @param head_ref A pointer to the head of the list.
 * @param new_data The data for the new node.
 */
void insert_at_end(Node **head_ref, int new_data) {
  Node *new_node = create_node(new_data);
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  Node *last = *head_ref;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = new_node;
}

/**
 * @brief Inserts a new node at a specific position in the list.
 * @param head_ref A pointer to the head of the list.
 * @param new_data The data for the new node.
 * @param position The 0-indexed position to insert the node at.
 */
void insert_at_position(Node **head_ref, int new_data, int position) {
  if (position < 0) {
    fprintf(stderr, "Position cannot be negative.\n");
    return;
  }
  if (position == 0) {
    insert_at_beginning(head_ref, new_data);
    return;
  }

  Node *new_node = create_node(new_data);
  Node *temp = *head_ref;
  int current_pos = 0;

  while (temp != NULL && current_pos < position - 1) {
    temp = temp->next;
    current_pos++;
  }

  if (temp == NULL) {
    fprintf(stderr, "Position out of bounds.\n");
    free(new_node); // Clean up the allocated node
    return;
  }

  new_node->next = temp->next;
  temp->next = new_node;
}

/**
 * @brief Deletes a node from the beginning of the list.
 * @param head_ref A pointer to the head of the list.
 */
void delete_from_beginning(Node **head_ref) {
  if (*head_ref == NULL) {
    return; // List is empty
  }
  Node *temp = *head_ref;
  *head_ref = (*head_ref)->next;
  free(temp);
}

/**
 * @brief Deletes a node from the end of the list.
 * @param head_ref A pointer to the head of the list.
 */
void delete_from_end(Node **head_ref) {
  if (*head_ref == NULL) {
    return; // List is empty
  }
  // If there is only one node
  if ((*head_ref)->next == NULL) {
    free(*head_ref);
    *head_ref = NULL;
    return;
  }
  Node *second_last = *head_ref;
  while (second_last->next->next != NULL) {
    second_last = second_last->next;
  }
  free(second_last->next);
  second_last->next = NULL;
}

/**
 * @brief Deletes a node at a specific position in the list.
 * @param head_ref A pointer to the head of the list.
 * @param position The 0-indexed position of the node to delete.
 */
void delete_node_by_position(Node **head_ref, int position) {
  if (*head_ref == NULL) {
    fprintf(stderr, "List is empty, cannot delete.\n");
    return;
  }

  if (position < 0) {
    fprintf(stderr, "Position cannot be negative.\n");
    return;
  }

  Node *temp = *head_ref;

  // If head needs to be removed
  if (position == 0) {
    *head_ref = temp->next; // Change head
    free(temp);             // free old head
    return;
  }

  // Find previous node of the node to be deleted
  for (int i = 0; temp != NULL && i < position - 1; i++) {
    temp = temp->next;
  }

  // If position is more than number of nodes
  if (temp == NULL || temp->next == NULL) {
    fprintf(stderr, "Position out of bounds.\n");
    return;
  }

  // Node temp->next is the node to be deleted
  // Store pointer to the next of node to be deleted
  Node *next_node = temp->next->next;

  // Unlink the node from linked list
  free(temp->next); // Free memory

  temp->next = next_node; // Unlink the deleted node from list
}

/**
 * @brief Deletes the first occurrence of a node with the given key.
 * @param head_ref A pointer to the head of the list.
 * @param key The data value of the node to be deleted.
 */
void delete_node_by_key(Node **head_ref, int key) {
  Node *temp = *head_ref;
  Node *prev = NULL;

  // If head node itself holds the key to be deleted
  if (temp != NULL && temp->data == key) {
    *head_ref = temp->next;
    free(temp);
    return;
  }

  // Search for the key to be deleted, keep track of the previous node
  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }

  // If key was not present in linked list
  if (temp == NULL)
    return;

  // Unlink the node from linked list
  prev->next = temp->next;
  free(temp);
}

/**
 * @brief Prints the linked list.
 * @param node The head of the list to print.
 */
void print_list(Node *node) {
  while (node != NULL) {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("NULL\n");
}
