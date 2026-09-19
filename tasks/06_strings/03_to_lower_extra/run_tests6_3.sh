#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "Hello, World! Im Student School21" "hello, world! im student school21"
run_case "ABC xyz 123!" "abc xyz 123!"
run_case "already lowercase" "already lowercase"
run_case "SCHOOL21" "school21"
run_case "AZaz" "azaz"
run_case "@[AZ" "@[az"
run_case "" ""
run_case_noeol "ABC" "abc"
run_case_devnull ""
run_case "  A  " "  a  "

check_memory "Hello, World!"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
