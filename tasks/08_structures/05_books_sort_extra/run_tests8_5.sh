#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "$(printf '4\nBrave New World\n1932\n1984\n1949\nAnimal Farm\n1945\nFahrenheit 451\n1953')" "$(printf '1932 Brave New World\n1945 Animal Farm\n1949 1984\n1953 Fahrenheit 451')"
run_case "$(printf '3\nZoo\n2000\nApple\n2000\nMango\n2000')" "$(printf '2000 Apple\n2000 Mango\n2000 Zoo')"
run_case "$(printf '1\nSolo\n2020')" "2020 Solo"
run_case "$(printf '2\nA\n1900\nB\n2000')" "$(printf '1900 A\n2000 B')"
run_case "$(printf '2\nB\n2000\nA\n1900')" "$(printf '1900 A\n2000 B')"

check_memory "$(printf '3\nZoo\n2000\nApple\n2000\nMango\n2000')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
