#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "a1b23c" "abc"
run_case "School21" "School"
run_case "Hello, World!" "Hello, World!"
run_case "1a2-b3!" "a-b!"
run_case "-12.5" "-."
run_case "0123456789" ""
run_case "0a9" "a"
run_case "" ""
run_case_devnull ""
run_case "7" ""
run_case "   " "   "
run_case "a 123 b" "a  b"
run_case " 1a2 " " a "
run_case_noeol "a1b2" "ab"
run_case "/09:" "/:"

check_memory "a1b23c"
check_memory "0123456789"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
