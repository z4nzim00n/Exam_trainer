#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

TMP_FILES="s1.txt s2.txt s3.txt s4.txt s5.txt b1.txt b2.txt b3.txt"
trap 'rm -f $TMP_FILES' EXIT

printf '1 2 3' > s1.txt
printf '10\n20\n30' > s2.txt
printf -- '-5 5 7' > s3.txt
printf '42' > s4.txt
printf '1 2\n' > s5.txt
printf '1 2 x' > b1.txt
printf '' > b2.txt
printf '1 2 3x' > b3.txt

compile -std=c11
check_style
check_static

run_case "s1.txt" "6"
run_case "s2.txt" "60"
run_case "s3.txt" "7"
run_case "s4.txt" "42"
run_case "s5.txt" "3"

run_case "b1.txt" "n/a"
run_case "b2.txt" "n/a"
run_case "b3.txt" "n/a"
run_case "nofile.txt" "n/a"
run_case_devnull "n/a"

check_memory "s1.txt"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi