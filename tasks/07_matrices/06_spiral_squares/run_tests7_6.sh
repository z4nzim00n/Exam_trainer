#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile
check_style
check_static

run_case "1" "0"
run_case "2" "$(printf '0 9\n1 4')"
run_case "3" "$(printf '0 49 36\n1 64 25\n4 9 16')"
run_case "0" "n/a"
run_case "-3" "n/a"
run_case "abc" "n/a"

check_memory "3"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
