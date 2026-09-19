#!/usr/bin/env bash
# Кладётся в саму папку задания, рядом с main.c.
# Пример: tasks/03_expressions/04_strictly_between/run_tests.sh
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

# Валидные данные
run_case "0 9 4" "1"
run_case "9 0 4" "1"
run_case "10 20 15" "1"
run_case "5 2 3" "1"
run_case "0 1 4" "0"
run_case "5 2 1" "0"
run_case "0 0 0" "0"
run_case "1 5 1" "0"
run_case "1 5 5" "0"
run_case "100 200 50" "0"
run_case "100 200 300" "0"

# Некорректные данные
run_case "0 9" "n/a"
run_case "a b c" "n/a"
run_case "0 9 xx" "n/a"

check_memory "0 9 4"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
