# EXAM_06_12 
# Удаление последнего вхождения подстроки — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Валидные данные

В таблице `\n` обозначает перевод строки между двумя входными строками.

| Основная строка | Подстрока | Результат | Команда | Пояснение |
| --- | --- | --- | --- | --- |
| `This is mytext` | `my` | `This is text` | `printf 'This is mytext\nmy\n' \| ./main` | Пример из условия |
| `abcabc` | `abc` | `abc` | `printf 'abcabc\nabc\n' \| ./main` | Удаляется последнее вхождение |
| `Hello, World!` | `xyz` | `Hello, World!` | `printf 'Hello, World!\nxyz\n' \| ./main` | Подстрока не найдена |
| `aaa` | `a` | `aa` | `printf 'aaa\na\n' \| ./main` | Удаляется последняя буква |
| `abcdef` | `abc` | `def` | `printf 'abcdef\nabc\n' \| ./main` | Подстрока в начале |
| `abcdef` | `def` | `abc` | `printf 'abcdef\ndef\n' \| ./main` | Подстрока в конце |
| `Hello Hello` | `Hello` | `Hello ` | `printf 'Hello Hello\nHello\n' \| ./main` | Пробел между словами остаётся |
| `mymymy` | `my` | `mymy` | `printf 'mymymy\nmy\n' \| ./main` | Несколько вхождений подряд |

## Важные случаи

В таблице ниже строки записаны в двойных кавычках, чтобы показать пустые строки и пробелы. Кавычки не входят во входные данные.

| Основная строка | Подстрока | Результат | Команда | Пояснение |
| --- | --- | --- | --- | --- |
| `""` | `""` | `""` | `printf '\n\n' \| ./main` | Обе строки пустые |
| `""` | `"a"` | `""` | `printf '\na\n' \| ./main` | Основная строка пустая |
| `"abc"` | `""` | `"abc"` | `printf 'abc\n\n' \| ./main` | Подстрока пустая |
| `"Text"` | `"text"` | `"Text"` | `printf 'Text\ntext\n' \| ./main` | Регистр учитывается |
| `"a b c"` | `" "` | `"a bc"` | `printf 'a b c\n \n' \| ./main` | Удаляется последний пробел |
| `"abc"` | `"abcd"` | `"abc"` | `printf 'abc\nabcd\n' \| ./main` | Подстрока длиннее строки |
| `"abc"` | `"abc"` | `""` | `printf 'abc\nabc\n' \| ./main` | Совпадение целиком |
| `"same"` | `"a"` | `"sme"` | `printf 'same\na' \| ./main` | Вторая строка завершается EOF |

## Проверка формата вывода

Посмотреть точные байты результата:

```bash
printf 'This is mytext\nmy\n' | ./main | od -An -t x1
```

Ожидается:

```text
54 68 69 73 20 69 73 20 74 65 78 74
```

Это символы `This is text` без завершающего перевода строки.

Проверка результата с одним пробелом в конце:

```bash
printf 'Hello Hello\nHello\n' | ./main | od -An -t x1
```

Ожидается:

```text
48 65 6c 6c 6f 20
```

Последний байт `20` — пробел, оставшийся между словами. Байта `0a` в конце быть не должно.

### Cppcheck

Статический анализ кода:

```bash
cppcheck --enable=all --suppress=missingIncludeSystem main.c
```

### Clang-format

Проверка стиля:

```bash
clang-format -n -Werror main.c
```

Автоматическое форматирование:

```bash
clang-format -i main.c
```

### Valgrind

Проверка одного вхождения:

```bash
printf 'This is mytext\nmy\n' | valgrind --leak-check=full ./main
```

Проверка нескольких вхождений:

```bash
printf 'abcabc\nabc\n' | valgrind --leak-check=full ./main
```

Проверка отсутствия подстроки:

```bash
printf 'Hello\nxyz\n' | valgrind --leak-check=full ./main
```

> Valgrind запускается уже на скомпилированном файле.