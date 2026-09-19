#!/usr/bin/env bash
# scripts/lib.sh — общие функции для run_tests.sh во всех папках заданий.
# Кладётся один раз в корень репозитория, в scripts/lib.sh.

# compile [доп. флаги gcc]
# Флаги передаются явно на каждый вызов (например "-std=c11" или "-lm"),
# потому что не все задания собираются одинаково — 3.1/3.2 нужен -lm БЕЗ
# -std=c11 (иначе M_PI не виден), 3.3/3.4/3.5 — наоборот, со -std=c11.
compile() {
  gcc -Wall -Wextra -Werror main.c -o main "$@"
}

check_style() {
  clang-format -n -Werror main.c
}

check_static() {
  cppcheck --enable=all --suppress=missingIncludeSystem main.c
}

# run_case "вход" "ожидаемый_вывод"
# Сравнение идёт через файлы + cmp, а не через $(...) — так сохраняется
# точная информация о наличии/отсутствии переноса строки в конце вывода.
run_case() {
  local input="$1" expected="$2"
  echo "$input" | ./main > /tmp/actual.out || true
  printf '%s' "$expected" > /tmp/expected.out
  if cmp -s /tmp/actual.out /tmp/expected.out; then
    echo "OK:   '$input' -> '$expected'"
  else
    # cat -A показывает $ на месте переноса строки — иначе баг с лишним \n
    # выглядит в логе так, будто "получили" и "ждали" совпадают.
    echo "FAIL: '$input' -> получили '$(cat -A /tmp/actual.out)', ждали '$expected'"
    FAILED=1
  fi
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
