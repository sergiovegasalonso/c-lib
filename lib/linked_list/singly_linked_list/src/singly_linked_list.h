#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

// node creation
Node *create_node(int data);

// insertion
void insert_at_beginning(Node **head_ref, int new_data);
void insert_at_end(Node **head_ref, int new_data);
void insert_at_position(Node **head_ref, int new_data, int position);

// deletion
void delete_from_beginning(Node **head_ref);
void delete_from_end(Node **head_ref);
void delete_node_by_position(Node **head_ref, int position);
void delete_node_by_key(Node **head_ref, int key);

// traversal and display
void print_list(Node *node);

#endif // SINGLY_LINKED_LIST_H