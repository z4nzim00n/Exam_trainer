# EXAM_08_02. Подсчёт букв и цифр — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

Для проверки эталона замените имя исходного файла на `solution.c` или `solution_commented.c`.

## Проверочные случаи

| Команда | Результат | Пояснение |
| --- | --- | --- |
| `printf 'School21!\n' \| ./main` | `6 2` | Буквы и цифры |
| `printf 'Hello, World!\n' \| ./main` | `10 0` | Только буквы и пунктуация |
| `printf '12345\n' \| ./main` | `0 5` | Каждая цифра считается отдельно |
| `printf 'a1 B2 c3!\n' \| ./main` | `3 3` | Смешанный ввод |
| `printf '!? --\n' \| ./main` | `0 0` | Нет букв и цифр |
| `printf 'AZaz09\n' \| ./main` | `4 2` | Границы диапазонов |
| `printf '@[/{:\n' \| ./main` | `0 0` | Символы вне нужных диапазонов |
| `printf '   \n' \| ./main` | `0 0` | Только пробелы |
| `printf '\n' \| ./main` | `0 0` | Пустая строка |
| `printf 'A1' \| ./main` | `1 1` | Завершение по EOF |
| `./main < /dev/null` | `0 0` | Пустой ввод |

## Максимальная длина

```bash
python3 -c 'print("a" * 50 + "7" * 50)' | ./main
```

Ожидается:

```text
50 50
```

Требуется Python 3.

## Точный формат вывода

```bash
printf 'School21!\n' | ./main | od -An -t x1
```

Ожидается:

```text
36 20 32
```

Это `6 2` без завершающего пробела и перевода строки.

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
printf 'a1 B2 c3!\n' | valgrind --leak-check=full --track-origins=yes ./main
```

> Проверьте исходник: функции `<ctype.h>` запрещены.