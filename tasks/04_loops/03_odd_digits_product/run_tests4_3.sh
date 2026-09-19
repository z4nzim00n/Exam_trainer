#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "1234" "3"
run_case "24" "0"
run_case "-3" "3"
run_case "13579" "945"
run_case "2468" "0"
run_case "11" "1"
run_case "0" "0"
run_case "abc" "n/a"
run_case "12abc" "n/a"
run_case "1.5" "n/a"

check_memory "1234"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
