#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile
check_style
check_static

run_case "1 1 2 2 3 -1" "1 2 3"
run_case "1 2 1 3 1 4 -1" "1 2 3 4"
run_case "5 2 5 1 2 -1" "5 2 1"
run_case "7 7 7 -1" "7"
run_case "0 1 0 -1" "0 1"
run_case "42 -1" "42"
run_case "-1" ""
run_case "abc" "n/a"
run_case "1 2 abc -1" "n/a"
run_case "1 -2 -1" "n/a"
run_case "1 2 3" "n/a"
run_case "" "n/a"

check_memory "1 2 1 3 1 4 -1"
check_memory "1 2 abc -1"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
