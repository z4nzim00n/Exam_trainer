#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile
check_style
check_static

run_case "$(printf '2\n1 2\n3 4\n5 6\n7 8')" "$(printf '19 22\n43 50')"
run_case "0" "n/a"
run_case "-1" "n/a"
run_case "abc" "n/a"
run_case "$(printf '2\n1 2\n3')" "n/a"

check_memory "$(printf '2\n1 2\n3 4\n5 6\n7 8')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
