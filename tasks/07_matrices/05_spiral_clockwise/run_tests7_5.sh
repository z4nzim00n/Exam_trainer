#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile
check_style
check_static

run_case "1" "1"
run_case "2" "$(printf '1 2\n4 3')"
run_case "3" "$(printf '1 2 3\n8 9 4\n7 6 5')"
run_case "4" "$(printf '1 2 3 4\n12 13 14 5\n11 16 15 6\n10 9 8 7')"
run_case "0" "n/a"
run_case "-5" "n/a"
run_case "abc" "n/a"

check_memory "3"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
