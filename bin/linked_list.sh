#!/bin/bash
cd "$(dirname "$0")"
set -eo pipefail

echo "⚠ Running linked list operations..."
../lib/linked_list/run.sh
echo "✓ Linked list operations completed."