#ifndef CODE_WARS_H
#define CODE_WARS_H

#include <stdbool.h>

/**
 * @brief DNA to RNA conversion function.
 * @param dna Pointer to the input DNA string.
 * @return Pointer to the newly allocated RNA string.
 */
char* dna_to_rna(const char* dna);

/**
 * @brief Validates if the given DNA sequence contains only valid nucleotides.
 * @param dna Pointer to the input DNA string.
 * @return true if the sequence is valid, false otherwise.
 */
bool is_valid_dna_sequence(const char* dna);

#endif  // CODE_WARS_H