#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>

/**
 * @brief Helper functions for printing integers.
 * @param data Pointer to the integer data.
 * @return void
 */
void print_int(void *data);

/**
 * @brief Helper function for comparing two integers.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 * @return Difference between the two integers.
 */
int compare_ints(void *a, void *b);

/**
 * @brief Helper functions for printing floats.
 * @param data Pointer to the float data.
 * @return void
 */
void print_float(void *data);

/**
 * @brief Helper function for comparing two floats.
 * @param a Pointer to the first float.
 * @param b Pointer to the second float.
 * @return Difference between the two floats.
 */
int compare_floats(void *a, void *b);

/**
 * @brief Helper functions for printing strings.
 * @param data Pointer to the string data.
 * @return void
 */
void print_string(void *data);

/**
 * @brief Helper function for comparing two strings.
 * @param a Pointer to the first string.
 * @param b Pointer to the second string.
 * @return Difference between the two strings.
 */
int compare_strings(void *a, void *b);

/**
 * @struct Person
 * @brief Represents a person with an ID and a name.
 */
typedef struct
{
    int id;
    char *name;
} Person;

/**
 * @brief Helper functions for printing Person structs.
 * @param data Pointer to the Person data.
 * @return void
 */
void print_person(void *data);

/**
 * @brief Helper function for comparing two Person structs.
 * @param a Pointer to the first Person.
 * @param b Pointer to the second Person.
 * @return 0 if equal, -1 otherwise.
 */
int compare_persons(void *a, void *b);

#endif  // HELPERS_H