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

    if (dna == NULL)
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
