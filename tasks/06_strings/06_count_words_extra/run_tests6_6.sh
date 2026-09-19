#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "Hello world" "2"
run_case " Hello,   world! " "2"
run_case "one two three" "3"
run_case "School21" "1"
run_case "123 + 456" "3"
run_case "a-b" "1"
run_case "!" "1"
run_case " a " "1"
run_case " " "0"
run_case "" "0"
run_case_noeol "one two" "2"
run_case_devnull "0"
run_case "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" "1"
run_case "a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a" "50"

check_memory "one two three"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
