# EXAM_08_05. Палиндром — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

Для проверки эталона замените имя исходного файла на `solution.c` или `solution_commented.c`.

## Проверочные случаи

| Команда | Результат | Пояснение |
| --- | --- | --- |
| `printf 'level\n' \| ./main` | `1` | Нечётная длина |
| `printf 'anna\n' \| ./main` | `1` | Чётная длина |
| `printf 'hello\n' \| ./main` | `0` | Не палиндром |
| `printf 'Anna\n' \| ./main` | `0` | Регистр учитывается |
| `printf '12321\n' \| ./main` | `1` | Цифры |
| `printf 'a b a\n' \| ./main` | `1` | Симметричные пробелы |
| `printf 'a!a\n' \| ./main` | `1` | Знак препинания в центре |
| `printf 'abca\n' \| ./main` | `0` | Крайние символы равны, внутренние — нет |
| `printf 'aa\n' \| ./main` | `1` | Два одинаковых символа |
| `printf 'ab\n' \| ./main` | `0` | Два разных символа |
| `printf 'a\n' \| ./main` | `1` | Один символ |
| `printf '   \n' \| ./main` | `1` | Только пробелы |
| `printf ' a\n' \| ./main` | `0` | Начальный пробел участвует в сравнении |
| `printf '\n' \| ./main` | `1` | Пустая строка |
| `printf 'level' \| ./main` | `1` | Завершение по EOF |
| `./main < /dev/null` | `1` | Пустой ввод |

## Максимальная длина

```bash
python3 -c 'print("a" * 100)' | ./main
```

Ожидается `1`.

```bash
python3 -c 'print("a" * 99 + "b")' | ./main
```

Ожидается `0`.

Требуется Python 3.

## Точный формат вывода

```bash
printf 'level\n' | ./main | od -An -t x1
```

Ожидается:

```text
31
```

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
printf 'abca\n' | valgrind --leak-check=full --track-origins=yes ./main
```

Проверка пустой строки:

```bash
printf '\n' | valgrind --leak-check=full --track-origins=yes ./main
```