#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

TMP_FILES="source1.txt source2.txt empty.txt copy1.txt copy2.txt copy3.txt destination.txt copy.txt"
trap 'rm -f $TMP_FILES' EXIT

printf 'Hello' > source1.txt
printf 'Hello\nWorld' > source2.txt
: > empty.txt
printf 'old content' > destination.txt

compile -std=c11
check_style
check_static

# Обычное копирование
run_case "$(printf 'source1.txt\ncopy1.txt')" ""
cmp source1.txt copy1.txt

# Сохранение переводов строк
run_case "$(printf 'source2.txt\ncopy2.txt')" ""
cmp source2.txt copy2.txt

# Копирование пустого файла
run_case "$(printf 'empty.txt\ncopy3.txt')" ""
[ ! -s copy3.txt ] || { echo "FAIL: copy3.txt должен быть пустым"; exit 1; }

# Перезапись существующего файла назначения
run_case "$(printf 'source1.txt\ndestination.txt')" ""
cmp source1.txt destination.txt

# Некорректные данные
run_case "$(printf 'missing.txt\ncopy.txt')" "n/a"
run_case "$(printf 'source1.txt\nsource1.txt')" "n/a"
run_case "$(printf 'source1.txt\n')" "n/a"
run_case "" "n/a"
run_case "$(printf 'source1.txt\n/no/such/dir/copy.txt')" "n/a"
run_case_devnull "n/a"

check_memory "$(printf 'source1.txt\ncopy1.txt')"

if [ -z "$FAILED" ]; then
    echo "Все тесты пройдены"
else
    echo "Есть проваленные тесты"
    exit 1
fi
