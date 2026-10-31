#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

# Валидные данные
run_case "$(printf '3\nAndrey\n15\nSergey\n20\nAnton\n10')" "Sergey"
run_case "$(printf '4\nAlice\n50\nBob\n80\nCarol\n60\nDave\n90')" "Bob, Dave"
run_case "$(printf '2\nA\n5\nB\n5')" ""
run_case "$(printf '1\nSolo\n50')" ""
run_case "$(printf '3\nA\n0\nB\n0\nC\n10')" "C"

# Некорректные данные
run_case "0" "n/a"
run_case "-1" "n/a"
run_case "abc" "n/a"
run_case "$(printf '2\nA\n5')" "n/a"
run_case "$(printf '1\nA\nx')" "n/a"

check_memory "$(printf '3\nAndrey\n15\nSergey\n20\nAnton\n10')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi