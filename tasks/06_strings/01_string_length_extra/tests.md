# EXAM_08_01. Длина строки — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

Для проверки эталона замените имя исходного файла на `solution.c` или `solution_commented.c`.

## Проверочные случаи

| Команда | Результат | Пояснение |
| --- | --- | --- |
| `printf 'Hello!\n' \| ./main` | `6` | Буквы и знак препинания |
| `printf 'School21\n' \| ./main` | `8` | Буквы и цифры |
| `printf 'Hello, World!\n' \| ./main` | `13` | Пробел тоже учитывается |
| `printf 'a b c\n' \| ./main` | `5` | Несколько слов |
| `printf '  a  \n' \| ./main` | `5` | Пробелы по краям |
| `printf '   \n' \| ./main` | `3` | Только пробелы |
| `printf 'a\n' \| ./main` | `1` | Один символ |
| `printf '\n' \| ./main` | `0` | Пустая строка |
| `printf 'abc' \| ./main` | `3` | Завершение по EOF |
| `./main < /dev/null` | `0` | Пустой ввод |

## Максимальная длина

Требуется Python 3:

```bash
python3 -c 'print("a" * 100)' | ./main
```

Ожидается:

```text
100
```

Вариант без перевода строки:

```bash
python3 -c 'import sys; sys.stdout.write("a" * 100)' | ./main
```

Ожидается `100`.

## Точный формат вывода

```bash
printf 'Hello!\n' | ./main | od -An -t x1
```

Ожидается:

```text
36
```

Байта `0a` в конце нет.

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
printf 'Hello, World!\n' | valgrind --leak-check=full --track-origins=yes ./main
```

Проверка пустого ввода:

```bash
valgrind --leak-check=full --track-origins=yes ./main < /dev/null
```

> Проверьте исходник: функция `strlen` запрещена. Строки длиннее 100 символов не входят в условия задачи.