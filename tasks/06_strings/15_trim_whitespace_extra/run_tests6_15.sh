#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "$(printf '   test   sample test\ttext')" "test sample test text"
run_case "$(printf ' \ttext')" "text"
run_case "$(printf ' \tt \t')" "t"
run_case "Hello world" "Hello world"
run_case "Hello    world" "Hello world"
run_case " Hello " "Hello"
run_case "1 2 3" "1 2 3"
run_case "$(printf 'a\tb\tc')" "a b c"
run_case "$(printf '\t\t\tabc\t\t\t')" "abc"
run_case "$(printf 'a \t b')" "a b"
run_case "$(printf '\t hello \t world \t')" "hello world"
run_case "" ""
run_case " " ""
run_case "$(printf '\t\t\t')" ""
run_case "$(printf ' \t \t ')" ""
run_case "a" "a"
run_case "$(printf '\ta\t')" "a"
run_case_devnull ""
run_case_noeol "$(printf 'a\tb')" "a b"

check_memory "$(printf '   test   sample test\ttext')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
