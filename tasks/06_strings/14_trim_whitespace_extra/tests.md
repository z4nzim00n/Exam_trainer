# EXAM_06_14. Удаление лишних пробелов и табуляций — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Валидные данные

В командах `\n` обозначает перевод строки, `\t` — табуляцию.

### С табуляциями (примеры из условия)

| Вход | Результат | Команда |
| --- | --- | --- |
| `   test   sample test\ttext` | `test sample test text` | `printf '   test   sample test\ttext\n' \| ./main` |
| `    \ttext` | `text` | `printf '    \ttext\n' \| ./main` |
| `            \tt \t` | `t` | `printf '            \tt \t\n' \| ./main` |

### Только пробелы

| Вход | Результат | Команда |
| --- | --- | --- |
| `Hello world` | `Hello world` | `printf 'Hello world\n' \| ./main` |
| `Hello    world` | `Hello world` | `printf 'Hello    world\n' \| ./main` |
| `   Hello   ` | `Hello` | `printf '   Hello   \n' \| ./main` |
| `1    2    3` | `1 2 3` | `printf '1    2    3\n' \| ./main` |

### Только табуляции

| Вход | Результат | Команда |
| --- | --- | --- |
| `a\tb\tc` | `a b c` | `printf 'a\tb\tc\n' \| ./main` |
| `\t\t\tabc\t\t\t` | `abc` | `printf '\t\t\tabc\t\t\t\n' \| ./main` |

### Смесь пробелов и табуляций

| Вход | Результат | Команда |
| --- | --- | --- |
| `a  \t  b` | `a b` | `printf 'a  \t  b\n' \| ./main` |
| `\t hello \t world \t` | `hello world` | `printf '\t hello \t world \t\n' \| ./main` |

## Важные случаи

Обозначение «пустой вывод» означает отсутствие любых символов, включая пробелы и переводы строк.

| Вход | Результат | Команда | Пояснение |
| --- | --- | --- | --- |
| `\n` | Пустой вывод | `printf '\n' \| ./main` | Пустая строка |
| `     \n` | Пустой вывод | `printf '     \n' \| ./main` | Только пробелы |
| `\t\t\t\n` | Пустой вывод | `printf '\t\t\t\n' \| ./main` | Только табуляции |
| ` \t \t \n` | Пустой вывод | `printf ' \t \t \n' \| ./main` | Смесь пробелов и табуляций |
| `a\n` | `a` | `printf 'a\n' \| ./main` | Один символ |
| `\ta\t\n` | `a` | `printf '\ta\t\n' \| ./main` | Один символ между табуляциями |
| Пустой ввод | Пустой вывод | `./main < /dev/null` | EOF до первого символа |
| `a\tb` без `\n` | `a b` | `printf 'a\tb' \| ./main` | Завершение по EOF |

## Проверка формата вывода

Посмотреть точные байты результата:

```bash
printf '   test   sample test\ttext\n' | ./main | od -An -t x1
```

Ожидается:

```text
74 65 73 74 20 73 61 6d 70 6c 65 20 74 65 73 74 20 74 65 78 74
```

Между словами код `20` — обычный пробел. Кода `09` (табуляция) в выводе быть не должно. Байта `0a` в конце тоже быть не должно.

Проверка пустого вывода:

```bash
printf '\t\t\t\n' | ./main | wc -c
```

Ожидается:

```text
0
```

### Cppcheck

```bash
cppcheck --enable=all --suppress=missingIncludeSystem main.c
```

### Clang-format

```bash
clang-format -n -Werror main.c
```

### Valgrind

```bash
printf '   test   sample test\ttext\n' | valgrind --leak-check=full ./main
```

> Valgrind запускается уже на скомпилированном файле.