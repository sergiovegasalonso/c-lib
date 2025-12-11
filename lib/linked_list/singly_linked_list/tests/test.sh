#!/bin/bash
cd "$(dirname "$0")"

gcc -O3 -Wall -Wextra -Werror -pedantic -std=c99 tests.c ../src/singly_linked_list.c -o tests && ./tests && rm tests