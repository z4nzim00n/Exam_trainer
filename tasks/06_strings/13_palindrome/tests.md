# EXAM_06_13 Проверка на палиндром — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Валидные данные

| Ввод | Вывод | Команда | Пояснение |
| --- | --- | --- | --- |
| `Mam mam` | `YES` | `printf 'Mam mam\n' \| ./main` | Пробел и регистр игнорируются |
| `Test1` | `NO` | `printf 'Test1\n' \| ./main` | Не палиндром |
| `racecar` | `YES` | `printf 'racecar\n' \| ./main` | Простой палиндром |
| `A man a plan a canal Panama` | `YES` | `printf 'A man a plan a canal Panama\n' \| ./main` | Классический пример |
| `12321` | `YES` | `printf '12321\n' \| ./main` | Палиндром из цифр |
| `12345` | `NO` | `printf '12345\n' \| ./main` | Цифры, не палиндром |
| `a` | `YES` | `printf 'a\n' \| ./main` | Один символ |
| `Aa` | `YES` | `printf 'Aa\n' \| ./main` | Разный регистр, одна буква |

## Важные случаи

| Ввод | Вывод | Команда | Пояснение |
| --- | --- | --- | --- |
| `   ` | `NO` | `printf '   \n' \| ./main` | Только пробелы |
| `a b a` | `YES` | `printf 'a b a\n' \| ./main` | Пробелы между буквами |
| `Ab Ba` | `YES` | `printf 'Ab Ba\n' \| ./main` | Регистр + пробел |
| `hello` | `NO` | `printf 'hello\n' \| ./main` | Обычная строка |
| `1a1` | `YES` | `printf '1a1\n' \| ./main` | Буквы и цифры |
| `a1b` | `NO` | `printf 'a1b\n' \| ./main` | Буквы и цифры, не палиндром |

## Проверка формата вывода

```bash
printf 'Mam mam\n' | ./main | od -An -t x1
```

Ожидается:

```text
59 45 53
```

Это `YES` без завершающего перевода строки.

```bash
printf 'Test1\n' | ./main | od -An -t x1
```

Ожидается:

```text
4e 4f
```

Это `NO` без завершающего перевода строки.

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
printf 'Mam mam\n' | valgrind --leak-check=full ./main
```

> Valgrind запускается уже на скомпилированном файле.