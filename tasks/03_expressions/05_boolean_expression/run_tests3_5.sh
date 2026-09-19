#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "1 1 1" "1"
run_case "0 0 0" "0"
run_case "1 0 0" "0"
run_case "0 1 1" "0"
run_case "1 1 0" "1"
run_case "1 0 1" "1"
run_case "0 0 1" "0"
run_case "100 0 1" "n/a"
run_case "abc" "n/a"
run_case "1 2 0" "n/a"
run_case "1 0 -1" "n/a"

check_memory "1 1 1"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
