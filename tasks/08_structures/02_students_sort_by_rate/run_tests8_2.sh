#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "$(printf '3\nAnton\n10\nSergey\n20\nAndrey\n30')" "$(printf 'Andrey 30\nSergey 20\nAnton 10')"
run_case "$(printf '4\nAlice\n75\nBob\n90\nCarol\n75\nDave\n60')" "$(printf 'Bob 90\nAlice 75\nCarol 75\nDave 60')"
run_case "$(printf '3\nA\n90\nB\n80\nC\n70')" "$(printf 'A 90\nB 80\nC 70')"
run_case "$(printf '3\nA\n10\nB\n20\nC\n30')" "$(printf 'C 30\nB 20\nA 10')"
run_case "$(printf '1\nSolo\n50')" "Solo 50"
run_case "$(printf '2\nAndrey Ivanov\n80\nSergey Petrov\n70')" "$(printf 'Andrey Ivanov 80\nSergey Petrov 70')"
run_case "$(printf '3\nA\n50\nB\n50\nC\n50')" "$(printf 'A 50\nB 50\nC 50')"
run_case "$(printf '3\nMax\n100\nMid\n50\nMin\n0')" "$(printf 'Max 100\nMid 50\nMin 0')"

check_memory "$(printf '3\nAnton\n10\nSergey\n20\nAndrey\n30')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
