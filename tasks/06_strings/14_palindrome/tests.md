# EXAM_06_14. Проверка на палиндром — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Валидные данные

| Ввод | Вывод | Команда | Пояснение |
| --- | --- | --- | --- |
| `Mam mam` | `YES` | `printf 'Mam mam\n' \| ./main` | регистр не важен, пробел стоит в середине |
| `Test1` | `NO` | `printf 'Test1\n' \| ./main` | первая и последняя цифры не совпадают |
| `racecar` | `YES` | `printf 'racecar\n' \| ./main` | простой палиндром |
| `A man a plan a canal Panama` | `NO` | `printf 'A man a plan a canal Panama\n' \| ./main` | пробелы значимы, симметрии нет |
| `12321` | `YES` | `printf '12321\n' \| ./main` | палиндром из цифр |
| `12345` | `NO` | `printf '12345\n' \| ./main` | цифры, не палиндром |
| `a` | `YES` | `printf 'a\n' \| ./main` | один символ |
| `Aa` | `YES` | `printf 'Aa\n' \| ./main` | после приведения к нижнему регистру `aa` |

## Важные случаи

| Ввод | Вывод | Команда | Пояснение |
| --- | --- | --- | --- |
| `   ` | `YES` | `printf '   \n' \| ./main` | три пробела симметричны |
| `a b a` | `YES` | `printf 'a b a\n' \| ./main` | пробелы стоят симметрично |
| `Ab Ba` | `YES` | `printf 'Ab Ba\n' \| ./main` | `ab ba` — палиндром |
| `hello` | `NO` | `printf 'hello\n' \| ./main` | обычная строка |
| `1a1` | `YES` | `printf '1a1\n' \| ./main` | буквы и цифры |
| `a1b` | `NO` | `printf 'a1b\n' \| ./main` | буквы и цифры, не палиндром |
| `ab a` | `NO` | `printf 'ab a\n' \| ./main` | пробел не совпадает с буквой |
| `abba ` | `NO` | `printf 'abba \n' \| ./main` | пробел в конце ломает симметрию |
| (пусто) | `YES` | `./main < /dev/null` | пустая строка считается палиндромом |

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
