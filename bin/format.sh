#!/bin/bash
cd "$(dirname "$0")"

find ../lib -name "*.c" -o -name "*.h" | xargs clang-format -i