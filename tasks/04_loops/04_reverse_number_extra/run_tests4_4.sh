#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "123" "321"
run_case "120" "21"
run_case "1000" "1"
run_case "7" "7"
run_case "0" "0"
run_case "10203" "30201"
run_case "1221" "1221"
run_case "123456789" "987654321"
run_case "999999999" "999999999"
run_case "100000000" "1"

check_memory "10203"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
