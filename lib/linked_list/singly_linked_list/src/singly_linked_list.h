#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct Node
 * @brief Represents a node in a singly linked list.
 */
typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

/**
 * @brief Creates a new node.
 * @param data The data to store in the new node.
 * @param data_size The size of the data to be stored.
 * @return A pointer to the newly created node.
 */
Node *create_node(void *data, size_t data_size);

/**
 * @brief Inserts a new node at the beginning of the list.
 * @param head_ref A pointer to the head of the list.
 * @param new_data The data for the new node.
 * @param data_size The size of the data to be stored.
 */
void insert_at_beginning(Node **head_ref, void *new_data, size_t data_size);

/**
 * @brief Inserts a new node at the end of the list.
 * @param head_ref A pointer to the head of the list.
 * @param new_data The data for the new node.
 * @param data_size The size of the data to be stored.
 */
void insert_at_end(Node **head_ref, void *new_data, size_t data_size);

/**
 * @brief Inserts a new node at a specific position in the list.
 * @param head_ref A pointer to the head of the list.
 * @param new_data The data for the new node.
 * @param data_size The size of the data to be stored.
 * @param position The 0-indexed position to insert the node at.
 */
void insert_at_position(Node **head_ref, void *new_data, size_t data_size,
                        int position);

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
 * @param compare A function pointer to compare the data.
 */
void delete_node_by_key(Node **head_ref, void *key,
                        int (*compare)(void *, void *));

/**
 * @brief Prints the linked list.
 * @param node The head of the list to print.
 * @param print_data A function pointer to print the data.
 */
void print_list(Node *node, void (*print_data)(void *));

#endif  // SINGLY_LINKED_LIST_H