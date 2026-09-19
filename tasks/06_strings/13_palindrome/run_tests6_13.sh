#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "Mam mam" "YES"
run_case "Test1" "NO"
run_case "racecar" "YES"
run_case "A man a plan a canal Panama" "YES"
run_case "12321" "YES"
run_case "12345" "NO"
run_case "a" "YES"
run_case "Aa" "YES"
run_case " " "NO"
run_case "a b a" "YES"
run_case "Ab Ba" "YES"
run_case "hello" "NO"
run_case "1a1" "YES"
run_case "a1b" "NO"

check_memory "A man a plan a canal Panama"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
