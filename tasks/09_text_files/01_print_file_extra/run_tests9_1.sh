#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

trap 'rm -f f1.txt f2.txt f3.txt' EXIT

printf 'Hello' > f1.txt
printf 'Hello\nWorld' > f2.txt
printf 'a b,c 123!' > f3.txt

compile -std=c11
check_style
check_static

run_case "f1.txt" "Hello"
run_case "f2.txt" "$(printf 'Hello\nWorld')"
run_case "f3.txt" "a b,c 123!"

run_case "nofile.txt" "n/a"
run_case_devnull "n/a"

check_memory "f2.txt"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi