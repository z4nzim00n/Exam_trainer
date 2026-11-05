#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

TMP_FILES="a1.txt a2.txt a3.txt a4.txt a5.txt a6.txt a7.txt a8.txt a9.txt a10.txt"
trap 'rm -f $TMP_FILES' EXIT

printf 'what???\n' > a1.txt
printf 'Test!? Yes!\n' > a2.txt
printf 'Hello world.\nHow are you?\nFine!\n' > a3.txt
printf 'no end\n' > a4.txt
printf '...!!!\n' > a5.txt
printf 'Wait... what?! Really?!\n' > a6.txt
printf '1.\n2!\n' > a7.txt
printf 'Hello\nworld.\n' > a8.txt
printf '' > a9.txt
printf 'S.M.A.R.T. Smart smart! Test test....\n' > a10.txt

compile -std=c11
check_style
check_static

# Валидные данные
run_case "a1.txt" "1"
run_case "a2.txt" "2"
run_case "a3.txt" "3"
run_case "a4.txt" "0"
run_case "a5.txt" "0"
run_case "a6.txt" "3"
run_case "a7.txt" "2"
run_case "a8.txt" "1"
run_case "a9.txt" "0"
# S.M.A.R.T. даёт 5 предложений, плюс "Smart smart!" и "Test test....", всего 7
run_case "a10.txt" "7"

# Некорректные данные
run_case "nofile.txt" "n/a"
run_case_devnull "n/a"

check_memory "a2.txt"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi