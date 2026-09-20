#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile
check_style
check_static

run_case "$(printf '4 3\n1 2 3\n4 5 6\n7 8 9\n10 11 12')" "$(printf '10 11 12\n4 5 6\n7 8 9\n1 2 3')"
run_case "$(printf '2 2\n5 5\n5 5')" "$(printf '5 5\n5 5')"
run_case "$(printf '3 2\n1 2\n3 4\n1 5')" "$(printf '1 5\n3 4\n1 2')"
run_case "$(printf '1 4\n9 8 7 6')" "9 8 7 6"
run_case "0 5" "n/a"
run_case "3 -2" "n/a"
run_case "abc 3" "n/a"
run_case "$(printf '2 2\n1 2\n3')" "n/a"

check_memory "$(printf '4 3\n1 2 3\n4 5 6\n7 8 9\n10 11 12')"
check_memory "$(printf '2 2\n1 2\n3')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
