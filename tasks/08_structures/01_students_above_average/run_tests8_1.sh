#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "$(printf '3\nAndrey\n15\nSergey\n20\nAnton\n10')" "Sergey"
run_case "$(printf '4\nAlice\n50\nBob\n80\nCarol\n60\nDave\n90')" "Bob, Dave"
run_case "$(printf '3\nA\n10\nB\n10\nC\n10')" ""
run_case "$(printf '1\nOne\n50')" ""
run_case "$(printf '2\nA\n10\nB\n20')" "B"
run_case "$(printf '3\nA\n10\nB\n11\nC\n12')" "C"
run_case "$(printf '3\nA\n10\nB\n10\nC\n11')" "C"
run_case "$(printf '2\nName With Spaces\n80\nAnother Name\n60')" "Name With Spaces"
run_case "$(printf '3\nA\n100\nB\n0\nC\n50')" "A"

check_memory "$(printf '3\nAndrey\n15\nSergey\n20\nAnton\n10')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
