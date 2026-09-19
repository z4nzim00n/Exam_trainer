#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "123" "3"
run_case "18" "8"
run_case "111111" "1"
run_case "0" "0"
run_case "-98765432" "9"
run_case "2468" "8"
run_case "90807" "9"
run_case "555559" "9"
run_case "abc" "n/a"
run_case "12abc" "n/a"
run_case "1.5" "n/a"

check_memory "123"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
