#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "159" "951"
run_case "120" "021"
run_case "-123" "-321"
run_case "777" "777"
run_case "951" "159"
run_case "100" "001"
run_case "-101" "-101"

check_memory "159"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
