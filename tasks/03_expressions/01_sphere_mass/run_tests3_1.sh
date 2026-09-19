#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

# Без -std=c11: он прячет M_PI (см. компиляцию ниже), поэтому здесь -lm без -std
compile -lm
check_style
check_static

run_case "1" "90059"
run_case "10" "90058989"
run_case "0" "0"
run_case "-1" "n/a"
run_case "abc" "n/a"

check_memory "1"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
