#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "Hello!" "6"
run_case "School21" "8"
run_case "Hello, World!" "13"
run_case "a b c" "5"
run_case "  a  " "5"
run_case "   " "3"
run_case "a" "1"
run_case "" "0"
run_case_noeol "abc" "3"
run_case_devnull "0"
run_case "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" "100"

check_memory "Hello, World!"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
