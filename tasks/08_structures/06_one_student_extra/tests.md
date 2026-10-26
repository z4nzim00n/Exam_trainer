# EXAM_08_06. Один студент — Тесты

## Компиляция

```
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Валидные данные

| Вход | Результат | Команда | Пояснение |
|---|---|---|---|
| `Andrey` `15` | `Andrey 15` | `printf 'Andrey\n15\n' \| ./main` | обычный случай |
| `Anna` `0` | `Anna 0` | `printf 'Anna\n0\n' \| ./main` | нулевая оценка |
| `Bob` `-3` | `Bob -3` | `printf 'Bob\n-3\n' \| ./main` | отрицательное число |
| `Andrey 15` (в одной строке) | `Andrey 15` | `echo "Andrey 15" \| ./main` | пробел тоже разделяет значения |

## Некорректные данные (n/a)

| Вход | Ожидаемый результат | Команда | Причина |
|---|---|---|---|
| `Andrey` `abc` | `n/a` | `printf 'Andrey\nabc\n' \| ./main` | оценка не число |
| `Andrey` | `n/a` | `echo "Andrey" \| ./main` | нет оценки |
| (пусто) | `n/a` | `./main < /dev/null` | ввода нет |

## Cppcheck, Clang-format

(те же блоки, что в других заданиях)

## Valgrind

```
printf 'Andrey\n15\n' | valgrind --leak-check=full ./main
```

Обратите внимание: Valgrind запускается уже на скомпилированном файле.