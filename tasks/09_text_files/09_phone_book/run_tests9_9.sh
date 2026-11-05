#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

# Тестовые файлы создаются здесь и удаляются при выходе
TMP_FILES="t1.txt t2.txt t3.txt e1.txt e2.txt e3.txt e4.txt e5.txt e6.txt e7.txt e8.txt e9.txt e10.txt"
trap 'rm -f $TMP_FILES' EXIT

printf 'Smith:8-950-111-22-33\nMiller:8-900-999-66-55' > t1.txt
printf 'Test:8-950-111-22-33\n' > t2.txt
printf 'A:8-000-000-00-00\nB:8-111-111-11-11\nC:8-222-222-22-22\n' > t3.txt

printf 'Smith:7-950-111-22-33' > e1.txt
printf 'Smith:8-950-11-122-33' > e2.txt
printf 'Smith:8-950-111-22-3a' > e3.txt
printf 'Smith8-950-111-22-33' > e4.txt
printf ':8-950-111-22-33' > e5.txt
printf 'Smith:8-950-111-22-333' > e6.txt
printf 'Smith:8-950-111-22-33\nBad:12345' > e7.txt
printf 'A:8-950-111-22-33\n\nB:8-900-999-66-55' > e8.txt
printf '' > e9.txt
printf 'Smith:8-950-111-22-33 ' > e10.txt

compile -std=c11
check_style
check_static

# Валидные данные
run_case "t1.txt" "$(printf 'Smith +7(950)111-22-33\nMiller +7(900)999-66-55')"
run_case "t2.txt" "Test +7(950)111-22-33"
run_case "t3.txt" "$(printf 'A +7(000)000-00-00\nB +7(111)111-11-11\nC +7(222)222-22-22')"

# Некорректные данные
run_case "e1.txt" "n/a"
run_case "e2.txt" "n/a"
run_case "e3.txt" "n/a"
run_case "e4.txt" "n/a"
run_case "e5.txt" "n/a"
run_case "e6.txt" "n/a"
run_case "e7.txt" "n/a"
run_case "e8.txt" "n/a"
run_case "e9.txt" "n/a"
run_case "e10.txt" "n/a"
run_case "nofile.txt" "n/a"
run_case_devnull "n/a"

check_memory "t1.txt"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi