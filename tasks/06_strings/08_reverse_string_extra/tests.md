# EXAM_08_04. Разворот строки — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

Для проверки эталона замените имя исходного файла на `solution.c` или `solution_commented.c`.

## Проверочные случаи

| Команда | Результат | Пояснение |
| --- | --- | --- |
| `printf 'Hello!\n' \| ./main` | `!olleH` | Буквы и пунктуация |
| `printf 'abc def\n' \| ./main` | `fed cba` | Разворачиваются все символы |
| `printf '12345\n' \| ./main` | `54321` | Цифры |
| `printf 'a\n' \| ./main` | `a` | Один символ |
| `printf 'ab\n' \| ./main` | `ba` | Два символа |
| `printf 'level\n' \| ./main` | `level` | Симметричная строка |
| `printf '\n' \| ./main` | Пустой вывод | Пустая строка |
| `printf 'abc' \| ./main` | `cba` | Завершение по EOF |
| `./main < /dev/null` | Пустой вывод | Нет символов |

## Пробелы по краям

Вход: два пробела, `ab`, один пробел.

```bash
printf '  ab \n' | ./main | od -An -t x1
```

Ожидается:

```text
20 62 61 20 20
```

Результат: один пробел, `ba`, два пробела. Конечные пробелы здесь правильны: они получены из начальных пробелов исходной строки.

## Только пробелы

```bash
printf '   \n' | ./main | od -An -t x1
```

Ожидается:

```text
20 20 20
```

## Максимальная длина

Требуется Python 3:

```bash
python3 - <<'PY'
import subprocess

text = "0123456789" * 10
result = subprocess.run(
    ["./main"], input=(text + "\n").encode(),
    capture_output=True, timeout=5
)

assert result.returncode == 0
assert result.stdout == text[::-1].encode(), repr(result.stdout)
print("OK")
PY
```

Сравнение побайтовое: лишний перевод строки приведёт к ошибке.

## Cppcheck

```bash
cppcheck --enable=all --suppress=missingIncludeSystem main.c
```

## Clang-format

```bash
clang-format -n -Werror main.c
```

Исправление форматирования:

```bash
clang-format -i main.c
```

## Valgrind

```bash
printf 'abc def\n' | valgrind --leak-check=full --track-origins=yes ./main
```

Проверка пустой строки:

```bash
printf '\n' | valgrind --leak-check=full --track-origins=yes ./main
```