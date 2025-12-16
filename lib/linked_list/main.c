#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../helpers/helpers.h"
#include "singly_linked_list/src/singly_linked_list.h"

int main()
{
    printf("\n");
    printf("Integer singly linked list\n");
    printf("==========================\n");
    Node *int_head = NULL;
    int int_val1 = 10, int_val2 = 20, int_val3 = 30, int_val4 = 40;

    insert_node_at_end(&int_head, &int_val1, sizeof(int));  // 10 -> NULL
    insert_node_at_end(&int_head, &int_val2, sizeof(int));  // 10 -> 20 -> NULL
    insert_node_at_beginning(&int_head, &int_val3,
                             sizeof(int));  // 30 -> 10 -> 20 -> NULL
    insert_node_at_position(&int_head, &int_val4, sizeof(int),
                            2);  // 30 -> 10 -> 40 -> 20 -> NULL

    printf("List: ");
    print_list(int_head, print_int);

    int key_to_delete = 20;
    printf("Deleting node with key: %d\n", key_to_delete);
    delete_node_by_key(&int_head, &key_to_delete,
                       compare_ints);  // 30 -> 10 -> 40 -> NULL

    printf("List: ");
    print_list(int_head, print_int);
    printf("\n");

    printf("Float singly linked list\n");
    printf("========================\n");
    Node *float_head = NULL;
    float float_val1 = 1.1f, float_val2 = 2.2f, float_val3 = 3.3f;

    insert_node_at_end(&float_head, &float_val1, sizeof(float));  // 1.1 -> NULL
    insert_node_at_end(&float_head, &float_val2,
                       sizeof(float));  // 1.1 -> 2.2 -> NULL
    insert_node_at_beginning(&float_head, &float_val3,
                             sizeof(float));  // 3.3 -> 1.1 -> 2.2 -> NULL

    printf("List: ");
    print_list(float_head, print_float);
    printf("\n");

    delete_node_by_position(&float_head, 20);  // 3.3 -> 1.1 -> 2.2 -> NULL

    printf("After attempting to delete at invalid position 20:\n");
    printf("List: ");
    print_list(float_head, print_float);
    printf("\n");

    printf("String singly linked list\n");
    printf("=========================\n");
    Node *string_head = NULL;
    char *str1 = "Hello";
    char *str2 = "World";
    char *str3 = "Test";

    insert_node_at_end(&string_head, str1,
                       strlen(str1) + 1);  // "Hello" -> NULL
    insert_node_at_end(&string_head, str2,
                       strlen(str2) + 1);  // "Hello" -> "World" -> NULL
    insert_node_at_beginning(
        &string_head, str3,
        strlen(str3) + 1);  // "Test" -> "Hello" -> "World" -> NULL
    insert_node_at_position(
        &string_head, "LinkedList", strlen("LinkedList") + 1,
        1);  // "Test" -> "LinkedList" -> "Hello" -> "World" -> NULL

    printf("List: ");
    print_list(string_head, print_string);

    char *key_str_to_delete = "World";
    printf("Deleting node with key: %s\n", key_str_to_delete);
    delete_node_by_key(
        &string_head, key_str_to_delete,
        compare_strings);  // "Test" -> "LinkedList" -> "Hello" -> NULL

    printf("List: ");
    print_list(string_head, print_string);
    printf("\n");

    printf("Deleting nodes from beginning one by one:\n");
    delete_node_from_beginning(
        &string_head);  // "LinkedList" -> "Hello" -> NULL
    delete_node_from_beginning(&string_head);  // "Hello" -> NULL
    delete_node_from_beginning(&string_head);  // NULL
    delete_node_from_beginning(&string_head);  // NULL

    printf("List: ");
    print_list(string_head, print_string);
    printf("\n");

    printf("Person (struct) singly linked list\n");
    printf("==================================\n");
    Node *person_head = NULL;
    Person p1 = {1, "Alice"};
    Person p2 = {2, "Bob"};
    Person p3 = {3, "Charlie"};

    insert_node_at_end(&person_head, &p1,
                       sizeof(Person));  // (1, "Alice") -> NULL
    insert_node_at_end(&person_head, &p2,
                       sizeof(Person));  // (1, "Alice") -> (2, "Bob") -> NULL
    insert_node_at_beginning(
        &person_head, &p3,
        sizeof(
            Person));  // (3, "Charlie") -> (1, "Alice") -> (2, "Bob") -> NULL

    printf("List: ");
    print_list(person_head, print_person);

    Person key_person_to_delete = {1, "Alice"};
    printf("Deleting node with key: (%d, %s)\n", key_person_to_delete.id,
           key_person_to_delete.name);
    delete_node_by_key(
        &person_head, &key_person_to_delete,
        compare_persons);  // (3, "Charlie") -> (2, "Bob") -> NULL

    printf("List: ");
    print_list(person_head, print_person);

    printf("Deleting node at position 0\n");
    delete_node_by_position(&person_head, 0);  // (2, "Bob") -> NULL

    printf("List: ");
    print_list(person_head, print_person);
    printf("\n");

    return 0;
}
