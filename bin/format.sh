#!/bin/bash
cd "$(dirname "$0")"
set -eo pipefail

echo "⚠ Formatting code..."
find ../lib -name "*.c" -o -name "*.h" | xargs clang-format -i
echo "✓ Format process completed."