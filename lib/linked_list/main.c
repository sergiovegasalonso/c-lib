#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "singly_linked_list/src/singly_linked_list.h"

// Example usage with integers
void print_int(void *data) { printf("%d", *(int *)data); }

int compare_int(void *a, void *b) { return (*(int *)a - *(int *)b); }

// Example usage with floats
void print_float(void *data) { printf("%f", *(float *)data); }

// Example usage with strings
void print_string(void *data) { printf("%s", (char *)data); }

int compare_string(void *a, void *b) { return strcmp((char *)a, (char *)b); }

// Example usage with a custom struct
typedef struct
{
    int id;
    char *name;
} Person;

void print_person(void *data)
{
    Person *p = (Person *)data;
    printf("(%d, %s)", p->id, p->name);
}

int main()
{
    // --- Integer List Example ---
    printf("--- Integer List ---\n");
    Node *int_head = NULL;
    int int_val1 = 10, int_val2 = 20, int_val3 = 30;

    insert_at_end(&int_head, &int_val1, sizeof(int));
    insert_at_end(&int_head, &int_val2, sizeof(int));
    insert_at_beginning(&int_head, &int_val3, sizeof(int));

    printf("List: ");
    print_list(int_head, print_int);

    int key_to_delete = 20;
    printf("Deleting node with key: %d\n", key_to_delete);
    delete_node_by_key(&int_head, &key_to_delete, compare_int);

    printf("List after deletion: ");
    print_list(int_head, print_int);
    printf("\n");

    // --- Float List Example ---
    printf("--- Float List ---\n");
    Node *float_head = NULL;
    float float_val1 = 1.1f, float_val2 = 2.2f, float_val3 = 3.3f;

    insert_at_end(&float_head, &float_val1, sizeof(float));
    insert_at_end(&float_head, &float_val2, sizeof(float));
    insert_at_beginning(&float_head, &float_val3, sizeof(float));

    printf("List: ");
    print_list(float_head, print_float);
    printf("\n");

    // --- String List Example ---
    printf("--- String List ---\n");
    Node *string_head = NULL;
    char *str1 = "Hello";
    char *str2 = "World";
    char *str3 = "Test";

    insert_at_end(&string_head, str1, strlen(str1) + 1);
    insert_at_end(&string_head, str2, strlen(str2) + 1);
    insert_at_beginning(&string_head, str3, strlen(str3) + 1);

    printf("List: ");
    print_list(string_head, print_string);

    char *key_str_to_delete = "World";
    printf("Deleting node with key: %s\n", key_str_to_delete);
    delete_node_by_key(&string_head, key_str_to_delete, compare_string);

    printf("List after deletion: ");
    print_list(string_head, print_string);
    printf("\n");

    // --- Person (Struct) List Example ---
    printf("--- Person (Struct) List ---\n");
    Node *person_head = NULL;
    Person p1 = {1, "Alice"};
    Person p2 = {2, "Bob"};

    insert_at_end(&person_head, &p1, sizeof(Person));
    insert_at_end(&person_head, &p2, sizeof(Person));

    printf("List: ");
    print_list(person_head, print_person);

    return 0;
}
