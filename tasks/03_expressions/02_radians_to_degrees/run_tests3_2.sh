#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -lm
check_style
check_static

run_case "1" "57"
run_case "2" "115"
run_case "0" "0"
run_case "0.5" "29"
run_case "-1" "-57"
run_case "abc" "n/a"
run_case "" "n/a"

check_memory "1"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
