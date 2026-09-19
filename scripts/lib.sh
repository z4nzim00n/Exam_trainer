#!/usr/bin/env bash
# scripts/lib.sh — общие функции для run_tests.sh во всех папках заданий.
# Кладётся один раз в корень репозитория, в scripts/lib.sh.

# compile [доп. флаги gcc]
# Флаги передаются явно на каждый вызов (например "-std=c11" или "-lm"),
# потому что не все задания собираются одинаково — 3.1/3.2 нужен -lm БЕЗ
# -std=c11 (иначе M_PI не виден), большинство остальных — со -std=c11.
compile() {
  gcc -Wall -Wextra -Werror main.c -o main "$@"
}

check_style() {
  clang-format -n -Werror main.c
}

check_static() {
  cppcheck --enable=all --suppress=missingIncludeSystem main.c
}

# Внутренний помощник: сравнивает /tmp/actual.out (уже записанный вызывающей
# функцией) с ожидаемым значением и печатает OK/FAIL. Сравнение идёт через
# файлы + cmp, а не через $(...), чтобы не терять инфомацию о наличии/отсутствии
# завершающего переноса строки.
_compare_and_report() {
  local label="$1" expected="$2"
  printf '%s' "$expected" > /tmp/expected.out
  if cmp -s /tmp/actual.out /tmp/expected.out; then
    echo "OK:   $label -> '$expected'"
  else
    # cat -A показывает $ на месте \n — иначе лишний перенос строки в выводе
    # выглядит в логе так, будто "получили" и "ждали" совпадают.
    echo "FAIL: $label -> получили '$(cat -A /tmp/actual.out)', ждали '$expected'"
    FAILED=1
  fi
}

# run_case "вход" "ожидаемый_вывод" — вход подаётся через echo (добавляет \n)
run_case() {
  local input="$1" expected="$2"
  echo "$input" | ./main > /tmp/actual.out || true
  _compare_and_report "'$input'" "$expected"
}

# run_case_noeol "вход" "ожидаемый_вывод" — вход БЕЗ завершающего \n
# (проверка завершения по EOF вместо перевода строки)
run_case_noeol() {
  local input="$1" expected="$2"
  printf '%s' "$input" | ./main > /tmp/actual.out || true
  _compare_and_report "'$input' (без \\n)" "$expected"
}

# run_case_devnull "ожидаемый_вывод" — вход полностью пуст, 0 байт
# (./main < /dev/null — EOF ещё до первого символа)
run_case_devnull() {
  local expected="$1"
  ./main < /dev/null > /tmp/actual.out || true
  _compare_and_report "(/dev/null)" "$expected"
}

# check_memory "вход"
check_memory() {
  local input="$1"
  if echo "$input" | valgrind --leak-check=full --error-exitcode=1 ./main > /dev/null 2>/tmp/valgrind.log; then
    :
  else
    echo "FAIL: valgrind нашёл проблему на входе '$input' (см. /tmp/valgrind.log)"
    FAILED=1
  fi
}
