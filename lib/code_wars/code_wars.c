#include "code_wars.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief DNA to RNA conversion function.
 * @param dna Pointer to the input DNA string.
 * @return Pointer to the newly allocated RNA string.
 */
char *dna_to_rna(const char *dna)
{
    const char THYMINE = 'T';
    const char URACIL = 'U';

    if (!is_valid_dna_sequence(dna))
    {
        return NULL;
    }

    size_t dna_len = strlen(dna);
    char *rna = calloc(dna_len + 1, sizeof(char));

    if (rna == NULL)
    {
        perror("calloc failed in dna_to_rna");
        return NULL;
    }

    for (size_t i = 0; i < dna_len; ++i)
    {
        rna[i] = (dna[i] == THYMINE) ? URACIL : dna[i];
    }

    return rna;
}

/**
 * @brief Validates if the given DNA sequence contains only valid nucleotides.
 * @param dna Pointer to the input DNA string.
 * @return true if the sequence is valid, false otherwise.
 */
bool is_valid_dna_sequence(const char *dna)
{
    if (dna == NULL)
    {
        return false;
    }

    const char ADENINE = 'A';
    const char THYMINE = 'T';
    const char CYTOSINE = 'C';
    const char GUANINE = 'G';
    const char VALID_NUCLEOTIDES[] = {ADENINE, THYMINE, CYTOSINE, GUANINE};
    size_t dna_len = strlen(dna);

    for (size_t i = 0; i < dna_len; ++i)
    {
        bool is_valid = false;
        for (size_t j = 0; j < sizeof(VALID_NUCLEOTIDES); ++j)
        {
            if (dna[i] == VALID_NUCLEOTIDES[j])
            {
                is_valid = true;
                break;
            }
        }

        if (!is_valid)
        {
            return false;
        }
    }

    return true;
}
