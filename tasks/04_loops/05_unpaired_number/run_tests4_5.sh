#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "1 2 1 -1" "2"
run_case "4 7 4 9 7 -1" "9"
run_case "5 -1" "5"
run_case "0 3 3 -1" "0"
run_case "0 7 0 -1" "7"
run_case "8 2 5 2 5 -1" "8"
run_case "2 5 2 5 8 -1" "8"
run_case "30000 42 30000 -1" "42"
run_case "5 -1 99" "5"

check_memory "4 7 4 9 7 -1"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
