#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "$(printf 'Andrey\n15')" "Andrey 15"
run_case "$(printf 'Anna\n0')" "Anna 0"
run_case "$(printf 'Bob\n-3')" "Bob -3"
run_case "Andrey 15" "Andrey 15"

run_case "$(printf 'Andrey\nabc')" "n/a"
run_case "Andrey" "n/a"
run_case_devnull "n/a"

check_memory "$(printf 'Andrey\n15')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi