#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "$(printf '2\n1 2\n3 4\n5 6\n7 8')" "$(printf '6 8\n10 12')"
run_case "$(printf '1\n-5\n8')" "3"
run_case "$(printf '2\n1 -2\n0 4\n-1 2\n0 -4')" "$(printf '0 0\n0 0')"
run_case "$(printf '2\n-1 -2\n-3 -4\n-5 -6\n-7 -8')" "$(printf -- '-6 -8\n-10 -12')"
run_case "$(printf '2\n100 -100\n100 -100\n100 -100\n-100 100')" "$(printf '200 -200\n0 0')"

check_memory "$(printf '2\n1 2\n3 4\n5 6\n7 8')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
