#include "singly_linked_list.h"

#include <string.h>

/**
 * @brief Creates a new node.
 * @param data The data to store in the new node.
 * @param data_size The size of the data to be stored.
 * @return A pointer to the newly created node.
 */
Node *create_node(void *data, size_t data_size)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        perror("Unable to allocate memory for new node");
        exit(EXIT_FAILURE);
    }

    new_node->data = malloc(data_size);
    if (new_node->data == NULL)
    {
        perror("Unable to allocate memory for data");
        free(new_node);
        exit(EXIT_FAILURE);
    }
    memcpy(new_node->data, data, data_size);
    new_node->next = NULL;

    return new_node;
}

/**
 * @brief Inserts a new node at the beginning of the list.
 * @param head_ref A pointer to the head of the list.
 * @param new_data The data for the new node.
 * @param data_size The size of the data to be stored.
 */
void insert_node_at_beginning(Node **head_ref, void *new_data, size_t data_size)
{
    Node *new_node = create_node(new_data, data_size);

    new_node->next = *head_ref;
    *head_ref = new_node;
}

/**
 * @brief Inserts a new node at the end of the list.
 * @param head_ref A pointer to the head of the list.
 * @param new_data The data for the new node.
 * @param data_size The size of the data to be stored.
 */
void insert_node_at_end(Node **head_ref, void *new_data, size_t data_size)
{
    Node *new_node = create_node(new_data, data_size);

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    Node *last = *head_ref;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

/**
 * @brief Inserts a new node at a specific position in the list.
 * @param head_ref A pointer to the head of the list.
 * @param new_data The data for the new node.
 * @param data_size The size of the data to be stored.
 * @param position The 0-indexed position to insert the node at.
 */
void insert_node_at_position(Node **head_ref, void *new_data, size_t data_size,
                             int position)
{
    if (position < 0)
    {
        fprintf(stderr, "Position cannot be negative.\n");
        return;
    }

    if (position == 0)
    {
        insert_node_at_beginning(head_ref, new_data, data_size);
        return;
    }

    Node *new_node = create_node(new_data, data_size);
    Node *temp = *head_ref;
    int current_pos = 0;

    while (temp != NULL && current_pos < position - 1)
    {
        temp = temp->next;
        current_pos++;
    }

    if (temp == NULL)
    {
        fprintf(stderr, "Position out of bounds.\n");
        free(new_node->data);
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

/**
 * @brief Deletes a node from the beginning of the list.
 * @param head_ref A pointer to the head of the list.
 */
void delete_node_from_beginning(Node **head_ref)
{
    if (*head_ref == NULL)
    {
        return;
    }

    Node *temp = *head_ref;

    *head_ref = (*head_ref)->next;
    free(temp->data);
    free(temp);
}

/**
 * @brief Deletes a node from the end of the list.
 * @param head_ref A pointer to the head of the list.
 */
void delete_node_from_end(Node **head_ref)
{
    if (*head_ref == NULL)
    {
        return;
    }

    if ((*head_ref)->next == NULL)
    {
        free((*head_ref)->data);
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    Node *second_last = *head_ref;

    while (second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }

    free(second_last->next->data);
    free(second_last->next);
    second_last->next = NULL;
}

/**
 * @brief Deletes a node at a specific position in the list.
 * @param head_ref A pointer to the head of the list.
 * @param position The 0-indexed position of the node to delete.
 */
void delete_node_by_position(Node **head_ref, int position)
{
    if (*head_ref == NULL)
    {
        fprintf(stderr, "List is empty, cannot delete.\n");
        return;
    }

    if (position < 0)
    {
        fprintf(stderr, "Position cannot be negative.\n");
        return;
    }

    Node *temp = *head_ref;

    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp->data);
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        fprintf(stderr, "Position out of bounds.\n");
        return;
    }

    Node *next_node = temp->next->next;

    free(temp->next->data);
    free(temp->next);
    temp->next = next_node;
}

/**
 * @brief Deletes the first occurrence of a node with the given key.
 * @param head_ref A pointer to the head of the list.
 * @param key The data value of the node to be deleted.
 * @param compare A function pointer to compare the data.
 */
void delete_node_by_key(Node **head_ref, void *key,
                        int (*compare)(void *, void *))
{
    Node *temp = *head_ref;
    Node *prev = NULL;

    if (temp != NULL && compare(temp->data, key) == 0)
    {
        *head_ref = temp->next;
        free(temp->data);
        free(temp);
        return;
    }

    while (temp != NULL && compare(temp->data, key) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp->data);
    free(temp);
}

/**
 * @brief Prints the linked list.
 * @param node The head of the list to print.
 * @param print_data A function pointer to print the data.
 */
void print_list(Node *node, void (*print_data)(void *))
{
    while (node != NULL)
    {
        print_data(node->data);
        printf(" -> ");
        node = node->next;
    }

    printf("NULL\n");
}
