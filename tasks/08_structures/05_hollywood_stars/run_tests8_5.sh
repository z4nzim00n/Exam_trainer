#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
source ../../../scripts/lib.sh

# -lm нужен для round
compile -std=c11 -lm
check_style
check_static

# Валидные данные
run_case "$(printf '2\nJohn\nWick\n190\nJohn\nKing\n180\nJohn')" "Wick, King: 185"
run_case "$(printf '4\nTom\nHanks\n183\nBrad\nPitt\n180\nTom\nCruise\n170\nTom\nHardy\n175\nTom')" "Hanks, Cruise, Hardy: 176"
run_case "$(printf '1\nTom\nHanks\n183\nTom')" "Hanks: 183"
run_case "$(printf '3\nAnn\nA\n180\nAnn\nB\n181\nAnn\nC\n181\nAnn')" "A, B, C: 181"
run_case "$(printf '3\nAnn\nA\n170\nBob\nB\n190\nAnn\nC\n180\nAnn')" "A, C: 175"
run_case "$(printf '2\nTom\nHanks\n183\ntom\nCruise\n170\nTom')" "Hanks: 183"
run_case "$(printf '2\nAnn\nA\n180\nAnn\nB\n185\nAnn')" "A, B: 183"

# Некорректные данные
run_case "$(printf '2\nBrad\nPitt\n180\nTom\nHanks\n183\nLeo')" "n/a"
run_case "0" "n/a"
run_case "-1" "n/a"
run_case "abc" "n/a"
run_case "$(printf '1\nTom\nHanks\nabc\nTom')" "n/a"
run_case "$(printf '1\nTom\nHanks\n183')" "n/a"

check_memory "$(printf '2\nJohn\nWick\n190\nJohn\nKing\n180\nJohn')"

if [ -z "$FAILED" ]; then
  echo "Все тесты пройдены"
else
  echo "Есть проваленные тесты"
  exit 1
fi