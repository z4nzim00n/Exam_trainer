# EXAM_08_03. Звёзды Голливуда — Тесты

## Компиляция

```
gcc -Wall -Wextra -Werror -std=c11 main.c -o main -lm
```

## Валидные данные

Многострочный ввод подаётся через `printf`: `\n` внутри него означает перевод строки.

| Вход | Результат | Команда | Пояснение |
|---|---|---|---|
| `2` John Wick 190, John King 180, `John` | `Wick, King: 185` | `printf '2\nJohn\nWick\n190\nJohn\nKing\n180\nJohn\n' \| ./main` | пример из условия |
| `4` Tom Hanks 183, Brad Pitt 180, Tom Cruise 170, Tom Hardy 175, `Tom` | `Hanks, Cruise, Hardy: 176` | `printf '4\nTom\nHanks\n183\nBrad\nPitt\n180\nTom\nCruise\n170\nTom\nHardy\n175\nTom\n' \| ./main` | среднее 528 / 3 = 176 |
| `1` Tom Hanks 183, `Tom` | `Hanks: 183` | `printf '1\nTom\nHanks\n183\nTom\n' \| ./main` | один совпавший |
| `3` Ann A 180, Ann B 181, Ann C 181, `Ann` | `A, B, C: 181` | `printf '3\nAnn\nA\n180\nAnn\nB\n181\nAnn\nC\n181\nAnn\n' \| ./main` | 180,67 → 181 |
| `3` Ann A 170, Bob B 190, Ann C 180, `Ann` | `A, C: 175` | `printf '3\nAnn\nA\n170\nBob\nB\n190\nAnn\nC\n180\nAnn\n' \| ./main` | Bob не входит в выборку |
| `2` Tom Hanks 183, tom Cruise 170, `Tom` | `Hanks: 183` | `printf '2\nTom\nHanks\n183\ntom\nCruise\n170\nTom\n' \| ./main` | регистр важен |
| `2` Ann A 180, Ann B 185, `Ann` | `A, B: 183` | `printf '2\nAnn\nA\n180\nAnn\nB\n185\nAnn\n' \| ./main` | среднее 182,5 → 183 (математическое округление) |

## Некорректные данные (n/a)

| Вход | Ожидаемый результат | Команда | Причина |
|---|---|---|---|
| `2` Brad Pitt 180, Tom Hanks 183, `Leo` | `n/a` | `printf '2\nBrad\nPitt\n180\nTom\nHanks\n183\nLeo\n' \| ./main` | людей с таким именем нет |
| `0` | `n/a` | `echo "0" \| ./main` | людей не может быть 0 |
| `-1` | `n/a` | `echo "-1" \| ./main` | отрицательное количество |
| `abc` | `n/a` | `echo "abc" \| ./main` | не число |
| `1` Tom Hanks `abc` | `n/a` | `printf '1\nTom\nHanks\nabc\nTom\n' \| ./main` | рост не число |
| `1` Tom Hanks 183 (без имени для поиска) | `n/a` | `printf '1\nTom\nHanks\n183\n' \| ./main` | нет искомого имени |

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

Проверка ошибок работы с памятью. В решении нет `malloc`, проверка полезна для контроля выхода за границы массива.

```
printf '2\nJohn\nWick\n190\nJohn\nKing\n180\nJohn\n' | valgrind --leak-check=full ./main
```

Обратите внимание: Valgrind запускается уже на скомпилированном файле.