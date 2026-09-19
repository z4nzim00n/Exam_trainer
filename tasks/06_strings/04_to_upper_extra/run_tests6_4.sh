#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "Hello, World! Im Student School21" "HELLO, WORLD! IM STUDENT SCHOOL21"
run_case "ABC xyz 123!" "ABC XYZ 123!"
run_case "ALREADY UPPERCASE" "ALREADY UPPERCASE"
run_case "school21" "SCHOOL21"
run_case "azAZ" "AZAZ"
run_case "{az}" "{AZ}"
run_case "" ""
run_case_noeol "abc" "ABC"
run_case_devnull ""
run_case "  a  " "  A  "

check_memory "Hello, World!"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
