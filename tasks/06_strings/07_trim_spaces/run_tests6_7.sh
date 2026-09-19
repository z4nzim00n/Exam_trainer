#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "Hello world" "Hello world"
run_case "Hello    world" "Hello world"
run_case " Hello" "Hello"
run_case "Hello " "Hello"
run_case " Hello, World! " "Hello, World!"
run_case " 1 2 3 " "1 2 3"
run_case "T e x t" "T e x t"
run_case " Hi, C! 21? " "Hi, C! 21?"
run_case "" ""
run_case " " ""
run_case "a" "a"
run_case " a " "a"
run_case "abc" "abc"
run_case_noeol " a b " "a b"
run_case_devnull ""
run_case "$(printf 'a b\nc d')" "a b"

check_memory "  Hello,    World!  "

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
