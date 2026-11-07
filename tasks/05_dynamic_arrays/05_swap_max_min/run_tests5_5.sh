#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

# Валидные данные
run_case "1 2 3 4 5 6 7 8 9 -1" "9 2 3 4 5 6 7 8 1"
run_case "5 1 1 1 5 9 9 9 5 -1" "5 9 1 1 5 1 9 9 5"
run_case "7 -1" "7"
run_case "3 3 3 -1" "3 3 3"
run_case "9 1 -1" "1 9"
run_case "1 5 5 9 1 -1" "9 5 5 1 1"
run_case "-5 2 8 -1" "8 2 -5"
run_case "$(printf '1\n2\n3\n-1')" "3 2 1"

# Некорректные данные
run_case "-1" "n/a"
run_case "1 2 a" "n/a"
run_case "1 2 3" "n/a"
run_case_devnull "n/a"

check_memory "1 2 3 4 5 6 7 8 9 -1"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi