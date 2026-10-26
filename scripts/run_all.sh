#!/usr/bin/env bash

cd "$(dirname "$0")/.."

case "$1" in
  --solution)
    export SOURCE_FILE=solution.c
    ;;
  --commented)
    export SOURCE_FILE=solution_commented.c
    ;;
  "")
    ;;
  *)
    echo "Неизвестный флаг: $1 (доступно: --solution, --commented)"
    exit 1
    ;;
esac

TOTAL=0
PASSED=0
FAILED_LIST=()

while IFS= read -r -d '' script; do
  TOTAL=$((TOTAL + 1))
  dir="$(dirname "$script")"
  if bash "$script" > /tmp/run_all_output.log 2>&1; then
    PASSED=$((PASSED + 1))
    echo "OK:   $dir"
  else
    echo "FAIL: $dir"
    FAILED_LIST+=("$dir")
    sed 's/^/       /' /tmp/run_all_output.log
  fi
done < <(find tasks -name 'run_tests*.sh' -print0 | sort -z)

echo ""
echo "Пройдено: $PASSED/$TOTAL"

if [ "$PASSED" -lt "$TOTAL" ]; then
  echo "Провалились:"
  for d in "${FAILED_LIST[@]}"; do
    echo "  - $d"
  done
  exit 1
fi
