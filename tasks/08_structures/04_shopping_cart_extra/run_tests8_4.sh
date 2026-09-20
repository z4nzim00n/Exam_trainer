#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

compile -std=c11
check_style
check_static

run_case "$(printf '3\nApple\n50\n10\nBread\n30\n2\nMilk\n80\n3')" "$(printf 'Apple 50 10 500\nBread 30 2 60\nMilk 80 3 240\nTotal 800')"
run_case "$(printf '1\nPen\n10\n5')" "$(printf 'Pen 10 5 50\nTotal 50')"
run_case "$(printf '2\nFree\n0\n10\nPaid\n100\n1')" "$(printf 'Free 0 10 0\nPaid 100 1 100\nTotal 100')"
run_case "$(printf '1\nExpensive\n10000\n10000')" "$(printf 'Expensive 10000 10000 100000000\nTotal 100000000')"

check_memory "$(printf '3\nApple\n50\n10\nBread\n30\n2\nMilk\n80\n3')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi
