#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "1 7 3" "21"
run_case "3 1 2 3 1 2 3" "14"
run_case "2 5 10 2 3" "40"
run_case "3 -1 2 -3 4 -5 6" "-32"
run_case "4 1 1 1 1 1 1 1 1" "4"
run_case "3 0 0 0 5 6 7" "0"
run_case "0" "n/a"
run_case "-1" "n/a"
run_case "abc" "n/a"
run_case "3 1 2" "n/a"
run_case "3 1 2 3 1 2" "n/a"

check_memory "3 1 2 3 1 2 3"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
