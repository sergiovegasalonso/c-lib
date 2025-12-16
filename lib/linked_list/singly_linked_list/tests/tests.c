#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/singly_linked_list.h"

void test_create_integer_node()
{
    printf("Integer singly linked list: testing create_node...");

    int data = 10;
    Node *node = create_node(&data, sizeof(int));

    assert(node != NULL);
    assert(*(int *)node->data == 10);
    assert(node->next == NULL);

    free(node->data);
    free(node);

    printf("PASSED ✓\n");
}

void test_create_float_node()
{
    printf("Float singly linked list: testing create_node...");

    float data = 10.0f;
    Node *node = create_node(&data, sizeof(float));

    assert(node != NULL);
    assert(*(float *)node->data == 10.0f);
    assert(node->next == NULL);

    free(node->data);
    free(node);

    printf("PASSED ✓\n");
}

void test_create_string_node()
{
    printf("String singly linked list: testing create_node...");

    char *data = "Hello";
    Node *node = create_node(data, strlen(data) + 1);

    assert(node != NULL);
    assert(strcmp((char *)node->data, "Hello") == 0);
    assert(node->next == NULL);

    free(node->data);
    free(node);

    printf("PASSED ✓\n");
}

void test_create_person_node()
{
    printf("Person singly linked list: testing create_node...");

    typedef struct
    {
        int id;
        char *name;
    } Person;

    Person p = {1, "Alice"};
    Node *node = create_node(&p, sizeof(Person));

    assert(node != NULL);
    Person *retrieved_person = (Person *)node->data;
    assert(retrieved_person->id == 1);
    assert(strcmp(retrieved_person->name, "Alice") == 0);
    assert(node->next == NULL);

    free(node->data);
    free(node);

    printf("PASSED ✓\n");
}

void test_insert_integer_at_beginning()
{
    printf("Integer singly linked list: testing insert_at_beginning...");

    Node *head = NULL;

    int data1 = 10;
    insert_at_beginning(&head, &data1, sizeof(int));

    assert(head != NULL);
    assert(*(int *)head->data == 10);

    int data2 = 20;
    insert_at_beginning(&head, &data2, sizeof(int));

    assert(*(int *)head->data == 20);
    assert(*(int *)head->next->data == 10);
    assert(head->next->next == NULL);

    delete_from_end(&head);
    delete_from_end(&head);

    printf("PASSED ✓\n");
}

void test_insert_float_at_beginning()
{
    printf("Float singly linked list: testing insert_at_beginning...");

    Node *head = NULL;

    float data1 = 10.0f;
    insert_at_beginning(&head, &data1, sizeof(float));

    assert(head != NULL);
    assert(*(float *)head->data == 10.0f);

    float data2 = 20.0f;
    insert_at_beginning(&head, &data2, sizeof(float));

    assert(*(float *)head->data == 20.0f);
    assert(*(float *)head->next->data == 10.0f);
    assert(head->next->next == NULL);

    delete_from_end(&head);
    delete_from_end(&head);

    printf("PASSED ✓\n");
}

void test_insert_string_at_beginning()
{
    printf("String singly linked list: testing insert_at_beginning...");

    Node *head = NULL;

    char *data1 = "World";
    insert_at_beginning(&head, data1, strlen(data1) + 1);

    assert(head != NULL);
    assert(strcmp((char *)head->data, "World") == 0);

    char *data2 = "Hello";
    insert_at_beginning(&head, data2, strlen(data2) + 1);

    assert(strcmp((char *)head->data, "Hello") == 0);
    assert(strcmp((char *)head->next->data, "World") == 0);
    assert(head->next->next == NULL);

    delete_from_end(&head);
    delete_from_end(&head);

    printf("PASSED ✓\n");
}

void test_insert_person_at_beginning()
{
    printf("Person singly linked list: testing insert_at_beginning...");

    typedef struct
    {
        int id;
        char *name;
    } Person;

    Node *head = NULL;

    Person p1 = {2, "Bob"};
    insert_at_beginning(&head, &p1, sizeof(Person));

    assert(head != NULL);
    Person *retrieved_person1 = (Person *)head->data;
    assert(retrieved_person1->id == 2);
    assert(strcmp(retrieved_person1->name, "Bob") == 0);

    Person p2 = {1, "Alice"};
    insert_at_beginning(&head, &p2, sizeof(Person));

    Person *retrieved_person2 = (Person *)head->data;
    assert(retrieved_person2->id == 1);
    assert(strcmp(retrieved_person2->name, "Alice") == 0);

    retrieved_person1 = (Person *)head->next->data;
    assert(retrieved_person1->id == 2);
    assert(strcmp(retrieved_person1->name, "Bob") == 0);
    assert(head->next->next == NULL);

    delete_from_end(&head);
    delete_from_end(&head);

    printf("PASSED ✓\n");
}

void test_insert_integer_at_end()
{
    printf("Integer singly linked list: testing insert_at_end...");

    Node *head = NULL;

    int data1 = 10;
    insert_at_end(&head, &data1, sizeof(int));

    assert(head != NULL);
    assert(*(int *)head->data == 10);

    int data2 = 20;
    insert_at_end(&head, &data2, sizeof(int));

    assert(head->next != NULL);
    assert(*(int *)head->next->data == 20);
    assert(head->next->next == NULL);

    delete_from_end(&head);
    delete_from_end(&head);

    printf("PASSED ✓\n");
}

void test_insert_float_at_end()
{
    printf("Float singly linked list: testing insert_at_end...");

    Node *head = NULL;

    float data1 = 10.0f;
    insert_at_end(&head, &data1, sizeof(float));

    assert(head != NULL);
    assert(*(float *)head->data == 10.0f);

    float data2 = 20.0f;
    insert_at_end(&head, &data2, sizeof(float));

    assert(head->next != NULL);
    assert(*(float *)head->next->data == 20.0f);
    assert(head->next->next == NULL);

    delete_from_end(&head);
    delete_from_end(&head);

    printf("PASSED ✓\n");
}

void test_insert_string_at_end()
{
    printf("String singly linked list: testing insert_at_end...");

    Node *head = NULL;

    char *data1 = "Hello";
    insert_at_end(&head, data1, strlen(data1) + 1);

    assert(head != NULL);
    assert(strcmp((char *)head->data, "Hello") == 0);

    char *data2 = "World";
    insert_at_end(&head, data2, strlen(data2) + 1);

    assert(head->next != NULL);
    assert(strcmp((char *)head->next->data, "World") == 0);
    assert(head->next->next == NULL);

    delete_from_end(&head);
    delete_from_end(&head);

    printf("PASSED ✓\n");
}

void test_insert_person_at_end()
{
    printf("Person singly linked list: testing insert_at_end...");

    typedef struct
    {
        int id;
        char *name;
    } Person;

    Node *head = NULL;

    Person p1 = {1, "Alice"};
    insert_at_end(&head, &p1, sizeof(Person));

    assert(head != NULL);
    Person *retrieved_person1 = (Person *)head->data;
    assert(retrieved_person1->id == 1);
    assert(strcmp(retrieved_person1->name, "Alice") == 0);

    Person p2 = {2, "Bob"};
    insert_at_end(&head, &p2, sizeof(Person));

    assert(head->next != NULL);
    Person *retrieved_person2 = (Person *)head->next->data;
    assert(retrieved_person2->id == 2);
    assert(strcmp(retrieved_person2->name, "Bob") == 0);
    assert(head->next->next == NULL);

    delete_from_end(&head);
    delete_from_end(&head);

    printf("PASSED ✓\n");
}

void test_insert_integer_at_position()
{
    printf("Integer singly linked list: testing insert_at_position...");

    Node *head = NULL;

    int data1 = 10;
    insert_at_end(&head, &data1, sizeof(int));
    int data2 = 30;
    insert_at_end(&head, &data2, sizeof(int));
    int data3 = 20;
    insert_at_position(&head, &data3, sizeof(int), 1);

    assert(*(int *)head->next->data == 20);

    int data4 = 5;
    insert_at_position(&head, &data4, sizeof(int), 0);

    assert(*(int *)head->data == 5);

    int data5 = 40;
    insert_at_position(&head, &data5, sizeof(int), 4);

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    assert(*(int *)temp->data == 40);

    while (head != NULL)
    {
        delete_from_beginning(&head);
    }

    printf("PASSED ✓\n");
}

void test_insert_float_at_position()
{
    printf("Float singly linked list: testing insert_at_position...");

    Node *head = NULL;

    float data1 = 10.0f;
    insert_at_end(&head, &data1, sizeof(float));
    float data2 = 30.0f;
    insert_at_end(&head, &data2, sizeof(float));
    float data3 = 20.0f;
    insert_at_position(&head, &data3, sizeof(float), 1);

    assert(*(float *)head->next->data == 20.0f);

    float data4 = 5.0f;
    insert_at_position(&head, &data4, sizeof(float), 0);

    assert(*(float *)head->data == 5.0f);

    float data5 = 40.0f;
    insert_at_position(&head, &data5, sizeof(float), 4);

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    assert(*(float *)temp->data == 40.0f);

    while (head != NULL)
    {
        delete_from_beginning(&head);
    }

    printf("PASSED ✓\n");
}

void test_insert_string_at_position()
{
    printf("String singly linked list: testing insert_at_position...");

    Node *head = NULL;

    char *data1 = "Hello";
    insert_at_end(&head, data1, strlen(data1) + 1);
    char *data2 = "World!";
    insert_at_end(&head, data2, strlen(data2) + 1);
    char *data3 = "Beautiful";
    insert_at_position(&head, data3, strlen(data3) + 1, 1);

    assert(strcmp((char *)head->next->data, "Beautiful") == 0);

    char *data4 = "Hey";
    insert_at_position(&head, data4, strlen(data4) + 1, 0);

    assert(strcmp((char *)head->data, "Hey") == 0);

    char *data5 = "Everyone";
    insert_at_position(&head, data5, strlen(data5) + 1, 4);

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    assert(strcmp((char *)temp->data, "Everyone") == 0);

    while (head != NULL)
    {
        delete_from_beginning(&head);
    }

    printf("PASSED ✓\n");
}

void test_insert_person_at_position()
{
    printf("Person singly linked list: testing insert_at_position...");

    typedef struct
    {
        int id;
        char *name;
    } Person;

    Node *head = NULL;

    Person p1 = {1, "Alice"};
    insert_at_end(&head, &p1, sizeof(Person));
    Person p2 = {3, "Charlie"};
    insert_at_end(&head, &p2, sizeof(Person));
    Person p3 = {2, "Bob"};
    insert_at_position(&head, &p3, sizeof(Person), 1);

    Person *retrieved_person = (Person *)head->next->data;
    assert(retrieved_person->id == 2);
    assert(strcmp(retrieved_person->name, "Bob") == 0);

    Person p4 = {0, "Zara"};
    insert_at_position(&head, &p4, sizeof(Person), 0);

    retrieved_person = (Person *)head->data;
    assert(retrieved_person->id == 0);
    assert(strcmp(retrieved_person->name, "Zara") == 0);

    Person p5 = {4, "David"};
    insert_at_position(&head, &p5, sizeof(Person), 4);

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    retrieved_person = (Person *)temp->data;
    assert(retrieved_person->id == 4);
    assert(strcmp(retrieved_person->name, "David") == 0);

    while (head != NULL)
    {
        delete_from_beginning(&head);
    }

    printf("PASSED ✓\n");
}

void test_delete_integer_from_beginning()
{
    printf("Integer singly linked list: testing delete_from_beginning...");

    Node *head = NULL;

    int data1 = 10;
    insert_at_end(&head, &data1, sizeof(int));
    int data2 = 20;
    insert_at_end(&head, &data2, sizeof(int));
    delete_from_beginning(&head);

    assert(head != NULL);
    assert(*(int *)head->data == 20);

    delete_from_beginning(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_float_from_beginning()
{
    printf("Float singly linked list: testing delete_from_beginning...");

    Node *head = NULL;

    float data1 = 10.0f;
    insert_at_end(&head, &data1, sizeof(float));
    float data2 = 20.0f;
    insert_at_end(&head, &data2, sizeof(float));
    delete_from_beginning(&head);

    assert(head != NULL);
    assert(*(float *)head->data == 20.0f);

    delete_from_beginning(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_string_from_beginning()
{
    printf("String singly linked list: testing delete_from_beginning...");

    Node *head = NULL;

    char *data1 = "Hello";
    insert_at_end(&head, data1, strlen(data1) + 1);
    char *data2 = "World";
    insert_at_end(&head, data2, strlen(data2) + 1);
    delete_from_beginning(&head);

    assert(head != NULL);
    assert(strcmp((char *)head->data, "World") == 0);

    delete_from_beginning(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_person_from_beginning()
{
    printf("Person singly linked list: testing delete_from_beginning...");

    typedef struct
    {
        int id;
        char *name;
    } Person;

    Node *head = NULL;

    Person p1 = {1, "Alice"};
    insert_at_end(&head, &p1, sizeof(Person));
    Person p2 = {2, "Bob"};
    insert_at_end(&head, &p2, sizeof(Person));
    delete_from_beginning(&head);

    assert(head != NULL);
    Person *retrieved_person = (Person *)head->data;
    assert(retrieved_person->id == 2);
    assert(strcmp(retrieved_person->name, "Bob") == 0);

    delete_from_beginning(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_integer_from_end()
{
    printf("Integer singly linked list: testing delete_from_end...");

    Node *head = NULL;

    int data1 = 10;
    insert_at_end(&head, &data1, sizeof(int));
    int data2 = 20;
    insert_at_end(&head, &data2, sizeof(int));
    delete_from_end(&head);

    assert(head != NULL);
    assert(head->next == NULL);
    assert(*(int *)head->data == 10);

    delete_from_end(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_float_from_end()
{
    printf("Float singly linked list: testing delete_from_end...");

    Node *head = NULL;

    float data1 = 10.0f;
    insert_at_end(&head, &data1, sizeof(float));
    float data2 = 20.0f;
    insert_at_end(&head, &data2, sizeof(float));
    delete_from_end(&head);

    assert(head != NULL);
    assert(head->next == NULL);
    assert(*(float *)head->data == 10.0f);

    delete_from_end(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_string_from_end()
{
    printf("String singly linked list: testing delete_from_end...");

    Node *head = NULL;

    char *data1 = "Hello";
    insert_at_end(&head, data1, strlen(data1) + 1);
    char *data2 = "World";
    insert_at_end(&head, data2, strlen(data2) + 1);
    delete_from_end(&head);

    assert(head != NULL);
    assert(head->next == NULL);
    assert(strcmp((char *)head->data, "Hello") == 0);

    delete_from_end(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_person_from_end()
{
    printf("Person singly linked list: testing delete_from_end...");

    typedef struct
    {
        int id;
        char *name;
    } Person;

    Node *head = NULL;

    Person p1 = {1, "Alice"};
    insert_at_end(&head, &p1, sizeof(Person));
    Person p2 = {2, "Bob"};
    insert_at_end(&head, &p2, sizeof(Person));
    delete_from_end(&head);

    assert(head != NULL);
    assert(head->next == NULL);
    Person *retrieved_person = (Person *)head->data;
    assert(retrieved_person->id == 1);
    assert(strcmp(retrieved_person->name, "Alice") == 0);

    delete_from_end(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_integer_by_position()
{
    printf("Integer singly linked list: testing delete_by_position...");

    Node *head = NULL;

    int data1 = 10;
    insert_at_end(&head, &data1, sizeof(int));
    int data2 = 20;
    insert_at_end(&head, &data2, sizeof(int));
    int data3 = 30;
    insert_at_end(&head, &data3, sizeof(int));
    int data4 = 40;
    insert_at_end(&head, &data4, sizeof(int));
    delete_node_by_position(&head, 2);

    assert(*(int *)head->next->next->data == 40);

    delete_node_by_position(&head, 0);

    assert(*(int *)head->data == 20);

    delete_node_by_position(&head, 1);

    assert(*(int *)head->data == 20);
    assert(head->next == NULL);

    delete_from_beginning(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_float_by_position()
{
    printf("Float singly linked list: testing delete_by_position...");

    Node *head = NULL;

    float data1 = 10.0f;
    insert_at_end(&head, &data1, sizeof(float));
    float data2 = 20.0f;
    insert_at_end(&head, &data2, sizeof(float));
    float data3 = 30.0f;
    insert_at_end(&head, &data3, sizeof(float));
    float data4 = 40.0f;
    insert_at_end(&head, &data4, sizeof(float));
    delete_node_by_position(&head, 2);

    assert(*(float *)head->next->next->data == 40.0f);

    delete_node_by_position(&head, 0);

    assert(*(float *)head->data == 20.0f);

    delete_node_by_position(&head, 1);

    assert(*(float *)head->data == 20.0f);
    assert(head->next == NULL);

    delete_from_beginning(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_string_by_position()
{
    printf("String singly linked list: testing delete_by_position...");

    Node *head = NULL;

    char *data1 = "Hello";
    insert_at_end(&head, data1, strlen(data1) + 1);
    char *data2 = "Beautiful";
    insert_at_end(&head, data2, strlen(data2) + 1);
    char *data3 = "World";
    insert_at_end(&head, data3, strlen(data3) + 1);
    char *data4 = "Everyone";
    insert_at_end(&head, data4, strlen(data4) + 1);
    delete_node_by_position(&head, 2);

    assert(strcmp((char *)head->next->next->data, "Everyone") == 0);

    delete_node_by_position(&head, 0);

    assert(strcmp((char *)head->data, "Beautiful") == 0);

    delete_node_by_position(&head, 1);

    assert(strcmp((char *)head->data, "Beautiful") == 0);
    assert(head->next == NULL);

    delete_from_beginning(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_person_by_position()
{
    printf("Person singly linked list: testing delete_by_position...");

    typedef struct
    {
        int id;
        char *name;
    } Person;

    Node *head = NULL;

    Person p1 = {1, "Alice"};
    insert_at_end(&head, &p1, sizeof(Person));
    Person p2 = {2, "Bob"};
    insert_at_end(&head, &p2, sizeof(Person));
    Person p3 = {3, "Charlie"};
    insert_at_end(&head, &p3, sizeof(Person));
    Person p4 = {4, "David"};
    insert_at_end(&head, &p4, sizeof(Person));
    delete_node_by_position(&head, 2);

    Person *retrieved_person = (Person *)head->next->next->data;
    assert(retrieved_person->id == 4);
    assert(strcmp(retrieved_person->name, "David") == 0);

    delete_node_by_position(&head, 0);

    retrieved_person = (Person *)head->data;
    assert(retrieved_person->id == 2);
    assert(strcmp(retrieved_person->name, "Bob") == 0);

    delete_node_by_position(&head, 1);

    retrieved_person = (Person *)head->data;
    assert(retrieved_person->id == 2);
    assert(strcmp(retrieved_person->name, "Bob") == 0);
    assert(head->next == NULL);

    delete_from_beginning(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

int compare_int(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

void test_delete_integer_by_key()
{
    printf("Integer singly linked list: testing delete_by_key...");

    Node *head = NULL;
    int data1 = 10;
    insert_at_end(&head, &data1, sizeof(int));
    int data2 = 20;
    insert_at_end(&head, &data2, sizeof(int));
    int data3 = 30;
    insert_at_end(&head, &data3, sizeof(int));
    int data4 = 40;
    insert_at_end(&head, &data4, sizeof(int));

    int key1 = 30;
    delete_by_key(&head, &key1, compare_int);

    assert(*(int *)head->next->next->data == 40);

    int key2 = 10;
    delete_by_key(&head, &key2, compare_int);

    assert(*(int *)head->data == 20);

    int key3 = 40;
    delete_by_key(&head, &key3, compare_int);

    assert(*(int *)head->data == 20);
    assert(head->next == NULL);

    delete_from_beginning(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_float_by_key()
{
    printf("Float singly linked list: testing delete_by_key...");

    Node *head = NULL;
    float data1 = 10.0f;
    insert_at_end(&head, &data1, sizeof(float));
    float data2 = 20.0f;
    insert_at_end(&head, &data2, sizeof(float));
    float data3 = 30.0f;
    insert_at_end(&head, &data3, sizeof(float));
    float data4 = 40.0f;
    insert_at_end(&head, &data4, sizeof(float));

    float key1 = 30.0f;
    delete_by_key(&head, &key1, compare_int);

    assert(*(float *)head->next->next->data == 40.0f);

    float key2 = 10.0f;
    delete_by_key(&head, &key2, compare_int);

    assert(*(float *)head->data == 20.0f);

    float key3 = 40.0f;
    delete_by_key(&head, &key3, compare_int);

    assert(*(float *)head->data == 20.0f);
    assert(head->next == NULL);

    delete_from_beginning(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_string_by_key()
{
    printf("String singly linked list: testing delete_by_key...");

    Node *head = NULL;
    char *data1 = "Hello";
    insert_at_end(&head, data1, strlen(data1) + 1);
    char *data2 = "Beautiful";
    insert_at_end(&head, data2, strlen(data2) + 1);
    char *data3 = "World";
    insert_at_end(&head, data3, strlen(data3) + 1);
    char *data4 = "Everyone";
    insert_at_end(&head, data4, strlen(data4) + 1);

    char *key1 = "World";
    delete_by_key(&head, key1, compare_int);

    assert(strcmp((char *)head->next->next->data, "Everyone") == 0);

    char *key2 = "Hello";
    delete_by_key(&head, key2, compare_int);

    assert(strcmp((char *)head->data, "Beautiful") == 0);

    char *key3 = "Everyone";
    delete_by_key(&head, key3, compare_int);

    assert(strcmp((char *)head->data, "Beautiful") == 0);
    assert(head->next == NULL);

    delete_from_beginning(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

void test_delete_person_by_key()
{
    printf("Person singly linked list: testing delete_by_key...");

    typedef struct
    {
        int id;
        char *name;
    } Person;

    Node *head = NULL;
    Person p1 = {1, "Alice"};
    insert_at_end(&head, &p1, sizeof(Person));
    Person p2 = {2, "Bob"};
    insert_at_end(&head, &p2, sizeof(Person));
    Person p3 = {3, "Charlie"};
    insert_at_end(&head, &p3, sizeof(Person));
    Person p4 = {4, "David"};
    insert_at_end(&head, &p4, sizeof(Person));

    Person key1 = {3, "Charlie"};
    delete_by_key(&head, &key1, compare_int);

    Person *retrieved_person = (Person *)head->next->next->data;
    assert(retrieved_person->id == 4);
    assert(strcmp(retrieved_person->name, "David") == 0);

    Person key2 = {1, "Alice"};
    delete_by_key(&head, &key2, compare_int);

    retrieved_person = (Person *)head->data;
    assert(retrieved_person->id == 2);
    assert(strcmp(retrieved_person->name, "Bob") == 0);

    Person key3 = {4, "David"};
    delete_by_key(&head, &key3, compare_int);

    retrieved_person = (Person *)head->data;
    assert(retrieved_person->id == 2);
    assert(strcmp(retrieved_person->name, "Bob") == 0);
    assert(head->next == NULL);

    delete_from_beginning(&head);

    assert(head == NULL);

    printf("PASSED ✓\n");
}

int main()
{
    test_create_integer_node();
    test_create_float_node();
    test_create_string_node();
    test_create_person_node();
    test_insert_integer_at_beginning();
    test_insert_float_at_beginning();
    test_insert_string_at_beginning();
    test_insert_person_at_beginning();
    test_insert_integer_at_end();
    test_insert_float_at_end();
    test_insert_string_at_end();
    test_insert_person_at_end();
    test_insert_integer_at_position();
    test_insert_float_at_position();
    test_insert_string_at_position();
    test_insert_person_at_position();
    test_delete_integer_from_beginning();
    test_delete_float_from_beginning();
    test_delete_string_from_beginning();
    test_delete_person_from_beginning();
    test_delete_integer_from_end();
    test_delete_float_from_end();
    test_delete_string_from_end();
    test_delete_person_from_end();
    test_delete_integer_by_position();
    test_delete_float_by_position();
    test_delete_string_by_position();
    test_delete_person_by_position();
    test_delete_integer_by_key();
    test_delete_float_by_key();
    test_delete_string_by_key();
    test_delete_person_by_key();

    return 0;
}
