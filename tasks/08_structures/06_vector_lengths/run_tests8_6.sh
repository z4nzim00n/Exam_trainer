#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

# -lm нужен для sqrt и round
compile -std=c11 -lm
check_style
check_static

# Валидные данные
run_case "$(printf '2\n0 0 0\n5 5 5\n2')" "9"
run_case "$(printf '3\n1 1 1\n2 2 2\n3 3 3\n4')" "5"
run_case "$(printf '2\n1 1 1\n2 2 2\n0')" "5"
run_case "$(printf '1\n3 4 0\n5')" "0"
run_case "$(printf '1\n3 4 0\n4.5')" "5"
run_case "$(printf '2\n3 0 0\n0 4 0\n2.5')" "7"
run_case "$(printf '1\n1 1 1\n10')" "0"
run_case "$(printf '1\n-3 -4 0\n1')" "5"

# Некорректные данные
run_case "0" "n/a"
run_case "-1" "n/a"
run_case "abc" "n/a"
run_case "$(printf '1\n1 2')" "n/a"
run_case "$(printf '1\n1 1 1')" "n/a"
run_case "$(printf '1\n1 1 x\n2')" "n/a"

check_memory "$(printf '3\n1 1 1\n2 2 2\n3 3 3\n4')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi