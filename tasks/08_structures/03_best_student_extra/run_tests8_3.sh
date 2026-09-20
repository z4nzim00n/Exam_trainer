#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "$(printf '3\nAnton\n10\nSergey\n20\nAndrey\n15')" "Sergey 20"
run_case "$(printf '4\nAlice\n80\nBob\n90\nCarol\n90\nDave\n70')" "Bob 90"
run_case "$(printf '1\nSolo\n50')" "Solo 50"
run_case "$(printf '3\nA\n100\nB\n100\nC\n100')" "A 100"
run_case "$(printf '2\nFirst\n0\nSecond\n1')" "Second 1"

check_memory "$(printf '3\nAnton\n10\nSergey\n20\nAndrey\n15')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
