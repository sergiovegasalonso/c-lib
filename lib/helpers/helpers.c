#include "helpers.h"

#include <string.h>

/**
 * @brief Helper functions for printing integers.
 * @param data Pointer to the integer data.
 * @return void
 */
void print_int(void *data)
{
    printf("%d", *(int *)data);
}

/**
 * @brief Helper function for comparing two integers.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 * @return Difference between the two integers.
 */
int compare_ints(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

/**
 * @brief Helper functions for printing floats.
 * @param data Pointer to the float data.
 * @return void
 */
void print_float(void *data)
{
    printf("%f", *(float *)data);
}

/**
 * @brief Helper function for comparing two floats.
 * @param a Pointer to the first float.
 * @param b Pointer to the second float.
 * @return Difference between the two floats.
 */
int compare_floats(void *a, void *b)
{
    float diff = (*(float *)a - *(float *)b);
    if (diff < 0.0f) return -1;
    if (diff > 0.0f) return 1;
    return 0;
}

/**
 * @brief Helper functions for printing strings.
 * @param data Pointer to the string data.
 * @return void
 */
void print_string(void *data)
{
    printf("%s", (char *)data);
}

/**
 * @brief Helper function for comparing two strings.
 * @param a Pointer to the first string.
 * @param b Pointer to the second string.
 * @return Difference between the two strings.
 */
int compare_strings(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}

/**
 * @brief Helper functions for printing Person structs.
 * @param data Pointer to the Person data.
 * @return void
 */
void print_person(void *data)
{
    Person *p = (Person *)data;
    printf("(%d, %s)", p->id, p->name);
}

/**
 * @brief Helper function for comparing two Person structs.
 * @param a Pointer to the first Person.
 * @param b Pointer to the second Person.
 * @return 0 if equal, -1 otherwise.
 */
int compare_persons(void *a, void *b)
{
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    if (p1->id == p2->id && strcmp(p1->name, p2->name) == 0) return 0;
    return -1;
}