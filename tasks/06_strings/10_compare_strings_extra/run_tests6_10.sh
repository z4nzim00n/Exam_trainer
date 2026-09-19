#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "$(printf 'Hello\nHello')" "1"
run_case "$(printf 'Hello\nhello')" "0"
run_case "$(printf 'abc\nabcd')" "0"
run_case "$(printf 'abcd\nabc')" "0"
run_case "$(printf 'abc\nxbc')" "0"
run_case "$(printf 'abc\naxc')" "0"
run_case "$(printf 'abc\nabx')" "0"
run_case "$(printf 'Hello world\nHello world')" "1"
run_case "$(printf 'School21!\nSchool21!')" "1"
run_case "$(printf '\n')" "1"
run_case "$(printf '\na')" "0"
run_case "$(printf 'a\n')" "0"
run_case "$(printf 'a\na')" "1"
run_case "$(printf 'a\nb')" "0"
run_case "$(printf ' \n ')" "1"
run_case "$(printf ' \n')" "0"
run_case "$(printf ' abc\nabc')" "0"
run_case "$(printf 'abc \nabc')" "0"
run_case "$(printf 'Hello world\nHello  world')" "0"
run_case_noeol "$(printf 'same\nsame')" "1"

check_memory "$(printf 'abcd\nabc')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
