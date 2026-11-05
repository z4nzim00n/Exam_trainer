#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

TMP_FILES="w1.txt w2.txt w3.txt w4.txt"
trap 'rm -f $TMP_FILES' EXIT

printf 'old content' > w4.txt

compile -std=c11
check_style
check_static

# Запись обычного текста
run_case "$(printf 'w1.txt\nHello')" ""
[ "$(cat w1.txt)" = "Hello" ] || { echo "FAIL: w1.txt"; exit 1; }

# Запись нескольких строк с сохранением перевода строки
run_case "$(printf 'w2.txt\nHello\nWorld')" ""
[ "$(cat w2.txt)" = "$(printf 'Hello\nWorld')" ] || { echo "FAIL: w2.txt"; exit 1; }

# Пустое содержимое
run_case "$(printf 'w3.txt\n')" ""
[ ! -s w3.txt ] || { echo "FAIL: w3.txt должен быть пустым"; exit 1; }

# Существующий файл должен быть перезаписан
run_case "$(printf 'w4.txt\nNew')" ""
[ "$(cat w4.txt)" = "New" ] || { echo "FAIL: w4.txt не перезаписан"; exit 1; }

# Некорректные данные
run_case "" "n/a"
run_case "$(printf '\n')" "n/a"
run_case "$(printf '/no/such/dir/out.txt\nHello')" "n/a"
run_case_devnull "n/a"

check_memory "$(printf 'w1.txt\nHello')"

if [ -z "$FAILED" ]; then
    echo "Все тесты пройдены"
else
    echo "Есть проваленные тесты"
    exit 1
fi
