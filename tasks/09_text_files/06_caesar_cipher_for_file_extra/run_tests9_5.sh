#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

# Временные файлы создаются здесь и удаляются при выходе
trap 'rm -f work.txt exp.txt' EXIT

# Проверка успешного случая: содержимое файла до, сдвиг, содержимое после.
# Вывод в stdout должен быть пустым.
check_file() {
  printf '%s' "$1" > work.txt
  printf '%s' "$3" > exp.txt
  out=$(printf 'work.txt\n%s\n' "$2" | ./main)
  if [ -n "$out" ] || ! cmp -s work.txt exp.txt; then
    echo "ПРОВАЛ: сдвиг $2"
    echo "ожидалось:"
    cat -A exp.txt
    echo
    echo "получено (файл) и вывод '$out':"
    cat -A work.txt
    echo
    FAILED=1
  fi
}

# Проверка ошибки: содержимое файла, строка для stdin (формат printf), ожидается "n/a".
check_na() {
  printf '%s' "$1" > work.txt
  out=$(printf "$2" | ./main)
  if [ "$out" != "n/a" ]; then
    echo "ПРОВАЛ: ввод '$2', ожидалось n/a, получено '$out'"
    FAILED=1
  fi
}

compile -std=c11
check_style
check_static

# Валидные данные
check_file 'Hello, World!' 3 'Khoor, Zruog!'
check_file 'xyz XYZ' 3 'abc ABC'
check_file 'abc' -1 'zab'
check_file 'Khoor' -3 'Hello'
check_file 'abc' 26 'abc'
check_file 'abc' 29 'def'
check_file 'abc' -27 'zab'
check_file 'abc' 0 'abc'
check_file $'abc\n' 1 $'bcd\n'
check_file $'Hello 123!\nSecond line' 1 $'Ifmmp 123!\nTfdpoe mjof'

# Некорректные данные
check_na 'abc' 'nofile.txt\n3\n'
check_na 'abc' 'work.txt\nabc\n'
check_na 'abc' 'work.txt\n'
check_na '' 'work.txt\n3\n'
check_na "$(head -c 1000 /dev/zero | tr '\0' 'a')" 'work.txt\n3\n'

out=$(./main < /dev/null)
if [ "$out" != "n/a" ]; then
  echo "ПРОВАЛ: пустой ввод, ожидалось n/a, получено '$out'"
  FAILED=1
fi

printf 'Hello' > work.txt
check_memory "$(printf 'work.txt\n3')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi