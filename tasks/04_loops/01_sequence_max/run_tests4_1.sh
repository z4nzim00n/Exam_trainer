#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "1000 -1" "1000"
run_case "1 2 3 4 3 2 1 -1" "4"
run_case "5 5 5 -1" "5"
run_case "3 -1" "3"
run_case "0 -1" "0"
run_case "1 0 5 2 -1" "5"
run_case "100 50 20 10 -1" "100"
run_case "1 2 3 -1 100" "3"
run_case "0 0 0 -1" "0"

check_memory "1 2 3 4 -1"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
