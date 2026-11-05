#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "my_var1" "Yes"
run_case "_" "Yes"
run_case "A" "Yes"
run_case "_a1B2" "Yes"
run_case_noeol "abc" "Yes"
run_case "1abc" "No"
run_case "a-b" "No"
run_case "a b" "No"
run_case "abc!" "No"
run_case "" "No"
run_case "привет" "No"

check_memory "my_var1"
check_memory "1abc"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi