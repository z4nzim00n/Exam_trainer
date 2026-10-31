#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

# Валидные данные
run_case "$(printf '3\nAnton\n10\nSergey\n20\nAndrey\n30')" "Andrey, Sergey, Anton"
run_case "$(printf '4\nAlice\n75\nBob\n90\nCarol\n75\nDave\n60')" "Bob, Alice, Carol, Dave"
run_case "$(printf '1\nSolo\n50')" "Solo"
run_case "$(printf '3\nA\n30\nB\n20\nC\n10')" "A, B, C"
run_case "$(printf '3\nA\n5\nB\n5\nC\n5')" "A, B, C"

# Некорректные данные
run_case "0" "n/a"
run_case "-1" "n/a"
run_case "abc" "n/a"
run_case "$(printf '2\nA\n5')" "n/a"
run_case "$(printf '1\nA\nx')" "n/a"

check_memory "$(printf '3\nAnton\n10\nSergey\n20\nAndrey\n30')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi