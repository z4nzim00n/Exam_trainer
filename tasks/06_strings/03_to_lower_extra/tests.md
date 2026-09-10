# EXAM_07_03. Перевод в нижний регистр — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

Для проверки эталона замените имя исходного файла на `solution.c` или `solution_commented.c`.

## Проверочные случаи

| Команда | Результат | Пояснение |
| --- | --- | --- |
| `printf 'Hello, World! Im Student School21\n' \| ./main` | `hello, world! im student school21` | Смешанный регистр |
| `printf 'ABC xyz 123!\n' \| ./main` | `abc xyz 123!` | Меняются только заглавные буквы |
| `printf 'already lowercase\n' \| ./main` | `already lowercase` | Изменения не нужны |
| `printf 'SCHOOL21\n' \| ./main` | `school21` | Заглавные буквы и цифры |
| `printf 'AZaz\n' \| ./main` | `azaz` | Границы буквенных диапазонов |
| `printf '@[AZ\n' \| ./main` | `@[az` | Символы рядом с диапазоном `'A'..'Z'` |
| `printf '\n' \| ./main` | Пустой вывод | Пустая строка |
| `printf 'ABC' \| ./main` | `abc` | Завершение по EOF |
| `./main < /dev/null` | Пустой вывод | Нет символов |

Кавычки оболочки не входят во входные данные.

## Точная проверка пробелов

```bash
printf '  A  \n' | ./main | od -An -t x1
```

Ожидается:

```text
20 20 61 20 20
```

Пробелы сохранены. Завершающего байта `0a` нет.

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

Valgrind проверяет уже скомпилированную программу.

> Кроме запуска тестов, проверьте исходник: функции `<ctype.h>` использовать нельзя.