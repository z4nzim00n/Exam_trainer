#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "$(printf '3\nAndrey\n15\nSergey\n20\nAnton\n10')" "45"
run_case "$(printf '1\nSolo\n7')" "7"
run_case "$(printf '2\nA\n-5\nB\n5')" "0"

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