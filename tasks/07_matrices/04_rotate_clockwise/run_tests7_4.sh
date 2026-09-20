#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile
check_style
check_static

run_case "$(printf '2 3\n1 2 3\n4 5 6')" "$(printf '4 1\n5 2\n6 3')"
run_case "$(printf '3 3\n1 2 3\n4 5 6\n7 8 9')" "$(printf '7 4 1\n8 5 2\n9 6 3')"
run_case "$(printf '3 1\n1\n2\n3')" "3 2 1"
run_case "$(printf '1 1\n42')" "42"
run_case "0 5" "n/a"
run_case "3 -2" "n/a"
run_case "abc 3" "n/a"
run_case "$(printf '2 2\n1 2\n3')" "n/a"

check_memory "$(printf '2 3\n1 2 3\n4 5 6')"
check_memory "$(printf '2 2\n1 2\n3')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
