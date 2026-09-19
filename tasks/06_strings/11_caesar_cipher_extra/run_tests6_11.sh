#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "$(printf '3\nHello, World!')" "Khoor, Zruog!"
run_case "$(printf '1\nxyz XYZ 123')" "yza YZA 123"
run_case "$(printf '0\nSchool21')" "School21"
run_case "$(printf '25\nAbc XYZ')" "Zab WXY"
run_case "$(printf '13\nHello')" "Uryyb"
run_case "$(printf '3\n123 !?-_')" "123 !?-_"
run_case "$(printf '3\n')" ""
run_case_noeol "$(printf '2\nAz')" "Cb"
run_case "$(printf '1\n  a Z  ')" "  b A  "

check_memory "$(printf '3\nHello, World!')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
