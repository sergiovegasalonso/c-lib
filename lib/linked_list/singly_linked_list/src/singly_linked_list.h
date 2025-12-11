#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct Node
 * @brief Represents a node in a singly linked list.
 */
typedef struct Node {
  int data;
  struct Node *next;
} Node;

/**
 * @brief Creates a new node.
 * @param data The data to store in the new node.
 * @return A pointer to the newly created node.
 */
Node *create_node(int data);

/**
 * @brief Inserts a new node at the beginning of the list.
 * @param head_ref A pointer to the head of the list.
 * @param new_data The data for the new node.
 */
void insert_at_beginning(Node **head_ref, int new_data);

/**
 * @brief Inserts a new node at the end of the list.
 * @param head_ref A pointer to the head of the list.
 * @param new_data The data for the new node.
 */
void insert_at_end(Node **head_ref, int new_data);

/**
 * @brief Inserts a new node at a specific position in the list.
 * @param head_ref A pointer to the head of the list.
 * @param new_data The data for the new node.
 * @param position The 0-indexed position to insert the node at.
 */
void insert_at_position(Node **head_ref, int new_data, int position);

/**
 * @brief Deletes a node from the beginning of the list.
 * @param head_ref A pointer to the head of the list.
 */
void delete_from_beginning(Node **head_ref);

/**
 * @brief Deletes a node from the end of the list.
 * @param head_ref A pointer to the head of the list.
 */
void delete_from_end(Node **head_ref);

/**
 * @brief Deletes a node at a specific position in the list.
 * @param head_ref A pointer to the head of the list.
 * @param position The 0-indexed position of the node to delete.
 */
void delete_node_by_position(Node **head_ref, int position);

/**
 * @brief Deletes the first occurrence of a node with the given key.
 * @param head_ref A pointer to the head of the list.
 * @param key The data value of the node to be deleted.
 */
void delete_node_by_key(Node **head_ref, int key);

/**
 * @brief Prints the linked list.
 * @param node The head of the list to print.
 */
void print_list(Node *node);

#endif // SINGLY_LINKED_LIST_H