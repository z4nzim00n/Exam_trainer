# EXAM_08_03. Подсчёт слов — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

Для проверки эталона замените имя исходного файла на `solution.c` или `solution_commented.c`.

## Проверочные случаи

| Команда | Результат | Пояснение |
| --- | --- | --- |
| `printf 'Hello world\n' \| ./main` | `2` | Два слова |
| `printf '  Hello,   world!  \n' \| ./main` | `2` | Повторные и крайние пробелы |
| `printf 'one two three\n' \| ./main` | `3` | Три слова |
| `printf 'School21\n' \| ./main` | `1` | Одно слово |
| `printf '123 + 456\n' \| ./main` | `3` | Знак `+` — отдельное слово |
| `printf 'a-b\n' \| ./main` | `1` | Дефис не разделяет слова |
| `printf '!\n' \| ./main` | `1` | Слово из знака препинания |
| `printf ' a \n' \| ./main` | `1` | Одно слово с пробелами по краям |
| `printf '     \n' \| ./main` | `0` | Только пробелы |
| `printf '\n' \| ./main` | `0` | Пустая строка |
| `printf 'one two' \| ./main` | `2` | Завершение по EOF |
| `./main < /dev/null` | `0` | Пустой ввод |

## Максимальная длина

Одно слово из 100 символов:

```bash
python3 -c 'print("a" * 100)' | ./main
```

Ожидается `1`.

Строка из 50 односимвольных слов и 50 пробелов:

```bash
python3 -c 'print("a " * 50)' | ./main
```

Ожидается `50`.

Требуется Python 3.

## Точный формат вывода

```bash
printf 'one two three\n' | ./main | od -An -t x1
```

Ожидается:

```text
33
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
printf '  Hello,   world!  \n' | valgrind --leak-check=full --track-origins=yes ./main
```

Проверка строки без слов:

```bash
printf '     \n' | valgrind --leak-check=full --track-origins=yes ./main
```

> Табуляции исключены условием. Единственный разделитель — обычный пробел.