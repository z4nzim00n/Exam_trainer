#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

# Тестовые файлы создаются здесь и удаляются при выходе
TMP_FILES="test_1.txt test_2.txt test_3.txt test_4.txt test_5.txt v1.txt v2.txt v3.txt v4.txt v5.txt v6.txt v7.txt e1.txt e2.txt e3.txt e4.txt e5.txt e6.txt e7.txt e8.txt e9.txt p1.txt p2.txt"
trap 'rm -f $TMP_FILES' EXIT

printf '100+100' > test_1.txt
printf '100++100' > test_2.txt
printf '100+100-100' > test_3.txt
printf '1+1\n2+2' > test_4.txt
printf '1+1\n100--100\n2+2' > test_5.txt

printf '5-10' > v1.txt
printf '0+0\n0-0' > v2.txt
printf '7\n' > v3.txt
printf '1+1\n2+2\n' > v4.txt
printf '007+003' > v5.txt
printf '999999999+999999999' > v6.txt
printf '10-5+3' > v7.txt

printf '1+' > e1.txt
printf '+1' > e2.txt
printf '1 + 1' > e3.txt
printf '1*2' > e4.txt
printf 'abc' > e5.txt
printf '1+-1' > e6.txt
printf '1234567890+1' > e7.txt
printf '' > e8.txt
printf '\n' > e9.txt

printf '1+1\n\n2+2' > p1.txt
printf '1+1\r\n2+2' > p2.txt

compile -std=c11
check_style
check_static

# Валидные данные
run_case "test_1.txt" "200"
run_case "test_3.txt" "100"
run_case "test_4.txt" "2, 4"
run_case "test_5.txt" "2, n/a, 4"
run_case "v1.txt" "-5"
run_case "v2.txt" "0, 0"
run_case "v3.txt" "7"
run_case "v4.txt" "2, 4"
run_case "v5.txt" "10"
run_case "v6.txt" "1999999998"
run_case "v7.txt" "8"

# Ошибка во всём файле
run_case "test_2.txt" "n/a"
run_case "e1.txt" "n/a"
run_case "e2.txt" "n/a"
run_case "e3.txt" "n/a"
run_case "e4.txt" "n/a"
run_case "e5.txt" "n/a"
run_case "e6.txt" "n/a"
run_case "e7.txt" "n/a"
run_case "e8.txt" "n/a"
run_case "e9.txt" "n/a"
run_case "nofile.txt" "n/a"
run_case_devnull "n/a"

# Плохая только одна строка
run_case "p1.txt" "2, n/a, 4"
run_case "p2.txt" "n/a, 4"

check_memory "test_5.txt"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi