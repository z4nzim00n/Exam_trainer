#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile
check_style
check_static

run_case "1 2 3 -1" "1 3 2"
run_case "1 2 3 4 5 6 -1" "1 6 2 5 3 4"
run_case "42 -1" "42"
run_case "0 5 0 -1" "0 0 5"
run_case "-1" "n/a"
run_case "1 2 -5 3 -1" "n/a"
run_case "1 2 abc -1" "n/a"
run_case "1 2 3" "n/a"

check_memory "1 2 3 4 5 6 -1"
check_memory "1 2 -5 -1"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
