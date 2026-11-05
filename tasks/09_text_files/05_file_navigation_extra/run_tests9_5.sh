#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

TMP_FILES="p1.txt p2.txt p3.txt empty.txt"
trap 'rm -f $TMP_FILES' EXIT

printf 'Hello' > p1.txt
printf 'abc\ndef' > p2.txt
printf 'Z' > p3.txt
: > empty.txt

compile -std=c11
check_style
check_static

# Валидные данные
run_case "$(printf 'p1.txt\n0')" "5 72"
run_case "$(printf 'p1.txt\n1')" "5 101"
run_case "$(printf 'p1.txt\n4')" "5 111"
run_case "$(printf 'p2.txt\n3')" "7 10"
run_case "$(printf 'p3.txt\n0')" "1 90"

# Некорректные данные
run_case "$(printf 'missing.txt\n0')" "n/a"
run_case "$(printf 'empty.txt\n0')" "n/a"
run_case "$(printf 'p1.txt\n5')" "n/a"
run_case "$(printf 'p1.txt\n10')" "n/a"
run_case "$(printf 'p1.txt\n-1')" "n/a"
run_case "$(printf 'p1.txt\nabc')" "n/a"
run_case "p1.txt" "n/a"
run_case "" "n/a"
run_case_devnull "n/a"

check_memory "$(printf 'p1.txt\n1')"

if [ -z "$FAILED" ]; then
    echo "Все тесты пройдены"
else
    echo "Есть проваленные тесты"
    exit 1
fi
