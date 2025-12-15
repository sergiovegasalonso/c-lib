#!/bin/bash
cd "$(dirname "$0")"

echo "⚠ Running tests..."
../lib/linked_list/singly_linked_list/tests/test.sh
echo "✓ Tests completed."