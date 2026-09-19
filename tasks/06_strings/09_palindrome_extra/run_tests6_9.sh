#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "level" "1"
run_case "anna" "1"
run_case "hello" "0"
run_case "Anna" "0"
run_case "12321" "1"
run_case "a b a" "1"
run_case "a!a" "1"
run_case "abca" "0"
run_case "aa" "1"
run_case "ab" "0"
run_case "a" "1"
run_case " " "1"
run_case " a" "0"
run_case "" "1"
run_case_noeol "level" "1"
run_case_devnull "1"
run_case "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" "1"
run_case "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab" "0"

check_memory "abca"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
