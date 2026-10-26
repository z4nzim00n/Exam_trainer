#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

TMP_FILES="c1.txt c2.txt c3.txt c4.txt c5.txt c6.txt c7.txt"
trap 'rm -f $TMP_FILES' EXIT

printf 'abcdef' > c1.txt
printf 'abc\ndef' > c2.txt
printf 'a-b-c' > c3.txt
printf 'zAB1' > c4.txt
printf 'Hello, World!' > c5.txt
printf 'Khoor' > c6.txt
printf 'abc' > c7.txt

compile -std=c11
check_style
check_static

# Валидные данные
run_case "$(printf 'c1.txt\n1')" "bcdefg"
run_case "$(printf 'c2.txt\n2')" "$(printf 'cde\nfgh')"
run_case "$(printf 'c3.txt\n1')" "b-c-d"
run_case "$(printf 'c4.txt\n1')" "aBC1"
run_case "$(printf 'c5.txt\n3')" "Khoor, Zruog!"
run_case "$(printf 'c6.txt\n-3')" "Hello"
run_case "$(printf 'c7.txt\n-1')" "zab"
run_case "$(printf 'c7.txt\n26')" "abc"
run_case "$(printf 'c7.txt\n29')" "def"
run_case "$(printf 'c7.txt\n-27')" "zab"

# Некорректные данные
run_case "$(printf 'nofile.txt\n1')" "n/a"
run_case "$(printf 'c1.txt\nabc')" "n/a"
run_case "c1.txt" "n/a"
run_case_devnull "n/a"

check_memory "$(printf 'c5.txt\n3')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi