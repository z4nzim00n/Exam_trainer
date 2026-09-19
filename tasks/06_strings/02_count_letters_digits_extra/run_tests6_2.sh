#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "School21!" "6 2"
run_case "Hello, World!" "10 0"
run_case "12345" "0 5"
run_case "a1 B2 c3!" "3 3"
run_case "!? --" "0 0"
run_case "AZaz09" "4 2"
run_case "@[/{:" "0 0"
run_case " " "0 0"
run_case "" "0 0"
run_case_noeol "A1" "1 1"
run_case_devnull "0 0"

check_memory "a1 B2 c3!"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
