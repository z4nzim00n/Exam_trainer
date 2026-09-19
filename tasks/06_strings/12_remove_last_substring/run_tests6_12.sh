#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "$(printf 'This is mytext\nmy')" "This is text"
run_case "$(printf 'abcabc\nabc')" "abc"
run_case "$(printf 'Hello, World!\nxyz')" "Hello, World!"
run_case "$(printf 'aaa\na')" "aa"
run_case "$(printf 'abcdef\nabc')" "def"
run_case "$(printf 'abcdef\ndef')" "abc"
run_case "$(printf 'Hello Hello\nHello')" "Hello "
run_case "$(printf 'mymymy\nmy')" "mymy"
run_case "$(printf '\n')" ""
run_case "$(printf '\na')" ""
run_case "$(printf 'abc\n')" "abc"
run_case "$(printf 'Text\ntext')" "Text"
run_case "$(printf 'a b c\n ')" "a bc"
run_case "$(printf 'abc\nabcd')" "abc"
run_case "$(printf 'abc\nabc')" ""
run_case_noeol "$(printf 'same\na')" "sme"

check_memory "$(printf 'This is mytext\nmy')"
check_memory "$(printf 'abcabc\nabc')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
