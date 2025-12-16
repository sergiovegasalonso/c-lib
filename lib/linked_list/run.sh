#!/bin/bash
cd "$(dirname "$0")"

gcc -O3 -Wall -Wextra -Werror -pedantic -std=c99 main.c singly_linked_list/src/singly_linked_list.c ../helpers/helpers.c -o main && ./main && rm main