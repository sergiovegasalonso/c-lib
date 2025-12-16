#!/bin/bash
cd "$(dirname "$0")"
set -eo pipefail

echo "⚠ Running tests..."
../lib/linked_list/singly_linked_list/tests/test.sh
echo "✓ Tests completed."