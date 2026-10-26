# EXAM_09_06_ALT. Шифр Цезаря для файла — Тесты

## Компиляция

```
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Подготовка тестовых файлов

```
printf 'abcdef' > c1.txt
printf 'abc\ndef' > c2.txt
printf 'a-b-c' > c3.txt
printf 'zAB1' > c4.txt
printf 'Hello, World!' > c5.txt
printf 'Khoor' > c6.txt
printf 'abc' > c7.txt
```

## Валидные данные

| Ввод (stdin) | Содержимое файла | Результат | Команда | Пояснение |
|---|---|---|---|---|
| `c1.txt` `1` | `abcdef` | `bcdefg` | `printf 'c1.txt\n1\n' \| ./main` | обычный сдвиг |
| `c2.txt` `2` | `abc`<br>`def` | `cde`<br>`fgh` | `printf 'c2.txt\n2\n' \| ./main` | перенос строки сохраняется |
| `c3.txt` `1` | `a-b-c` | `b-c-d` | `printf 'c3.txt\n1\n' \| ./main` | знаки не меняются |
| `c4.txt` `1` | `zAB1` | `aBC1` | `printf 'c4.txt\n1\n' \| ./main` | переход через `z`, регистр, цифра |
| `c5.txt` `3` | `Hello, World!` | `Khoor, Zruog!` | `printf 'c5.txt\n3\n' \| ./main` | пробел и знаки |
| `c6.txt` `-3` | `Khoor` | `Hello` | `printf 'c6.txt\n-3\n' \| ./main` | расшифровка |
| `c7.txt` `-1` | `abc` | `zab` | `printf 'c7.txt\n-1\n' \| ./main` | отрицательный ключ |
| `c7.txt` `26` | `abc` | `abc` | `printf 'c7.txt\n26\n' \| ./main` | полный круг |
| `c7.txt` `29` | `abc` | `def` | `printf 'c7.txt\n29\n' \| ./main` | ключ больше 26 |
| `c7.txt` `-27` | `abc` | `zab` | `printf 'c7.txt\n-27\n' \| ./main` | отрицательный ключ больше 26 |

## Некорректные данные (n/a)

| Ввод (stdin) | Ожидаемый результат | Команда | Причина |
|---|---|---|---|
| `nofile.txt` `1` | `n/a` | `printf 'nofile.txt\n1\n' \| ./main` | файла нет |
| `c1.txt` `abc` | `n/a` | `printf 'c1.txt\nabc\n' \| ./main` | ключ не число |
| `c1.txt` | `n/a` | `printf 'c1.txt\n' \| ./main` | ключ не задан |
| (пусто) | `n/a` | `./main < /dev/null` | ввода нет |

## Cppcheck

Статический анализ кода. Нужен, чтобы найти потенциальные ошибки и подозрительные места в исходнике, которые компилятор может не заметить.

```
cppcheck --enable=all --suppress=missingIncludeSystem main.c
```

## Clang-format

Проверка стиля и форматирования кода.

```
clang-format -n -Werror main.c
```

Если нужно автоматически отформатировать файл:

```
clang-format -i main.c
```

## Valgrind

Незакрытый файл будет показан как утечка.

```
printf 'c5.txt\n3\n' | valgrind --leak-check=full ./main
```

Обратите внимание: Valgrind запускается уже на скомпилированном файле.