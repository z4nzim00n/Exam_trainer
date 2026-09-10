# EXAM_07_04. Перевод в верхний регистр — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

Для проверки эталона замените имя исходного файла на `solution.c` или `solution_commented.c`.

## Проверочные случаи

| Команда | Результат | Пояснение |
| --- | --- | --- |
| `printf 'Hello, World! Im Student School21\n' \| ./main` | `HELLO, WORLD! IM STUDENT SCHOOL21` | Смешанный регистр |
| `printf 'ABC xyz 123!\n' \| ./main` | `ABC XYZ 123!` | Меняются только строчные буквы |
| `printf 'ALREADY UPPERCASE\n' \| ./main` | `ALREADY UPPERCASE` | Изменения не нужны |
| `printf 'school21\n' \| ./main` | `SCHOOL21` | Буквы и цифры |
| `printf 'azAZ\n' \| ./main` | `AZAZ` | Границы диапазонов |
| `printf '{az}\n' \| ./main` | `{AZ}` | Пунктуация сохраняется |
| `printf '\n' \| ./main` | Пустой вывод | Пустая строка |
| `printf 'abc' \| ./main` | `ABC` | Завершение по EOF |
| `./main < /dev/null` | Пустой вывод | Нет символов |

## Точная проверка пробелов

```bash
printf '  a  \n' | ./main | od -An -t x1
```

Ожидается:

```text
20 20 41 20 20
```

Пробелы сохранены, байта `0a` в конце нет.

## Cppcheck

```bash
cppcheck --enable=all --suppress=missingIncludeSystem main.c
```

## Clang-format

```bash
clang-format -n -Werror main.c
```

Автоматическое форматирование:

```bash
clang-format -i main.c
```

## Valgrind

```bash
printf 'Hello, World!\n' | valgrind --leak-check=full --track-origins=yes ./main
```

Valgrind запускается на скомпилированной программе.

> Проверьте исходник: функции `<ctype.h>` использовать нельзя.