#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "Hello!" "!olleH"
run_case "abc def" "fed cba"
run_case "12345" "54321"
run_case "a" "a"
run_case " ab " " ba "
run_case "" ""
run_case_devnull ""
run_case_noeol "same" "emas"
run_case "!@#" "#@!"

check_memory "Hello!"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
