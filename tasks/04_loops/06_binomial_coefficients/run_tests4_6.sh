#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "3" "1 3 3 1"
run_case "0" "1"
run_case "1" "1 1"
run_case "4" "1 4 6 4 1"
run_case "5" "1 5 10 10 5 1"
run_case "21" "1 21 210 1330 5985 20349 54264 116280 203490 293930 352716 352716 293930 203490 116280 54264 20349 5985 1330 210 21 1"
run_case "-1" "n/a"
run_case "abc" "n/a"
run_case "" "n/a"
run_case "3 x" "n/a"

check_memory "5"
check_memory "-1"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi