# EXAM_09_08. Сумма чисел из файла — Тесты

## Компиляция

```
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Подготовка тестовых файлов

```
printf '1 2 3' > s1.txt
printf '10\n20\n30' > s2.txt
printf -- '-5 5 7' > s3.txt
printf '42' > s4.txt
printf '1 2\n' > s5.txt
printf '1 2 x' > b1.txt
printf '' > b2.txt
printf '1 2 3x' > b3.txt
```

## Валидные данные

| Ввод (stdin) | Содержимое файла | Результат | Команда | Пояснение |
|---|---|---|---|---|
| `s1.txt` | `1 2 3` | `6` | `echo "s1.txt" \| ./main` | числа через пробел |
| `s2.txt` | `10`<br>`20`<br>`30` | `60` | `echo "s2.txt" \| ./main` | числа в столбик |
| `s3.txt` | `-5 5 7` | `7` | `echo "s3.txt" \| ./main` | отрицательные числа |
| `s4.txt` | `42` | `42` | `echo "s4.txt" \| ./main` | одно число |
| `s5.txt` | `1 2` и `\n` в конце | `3` | `echo "s5.txt" \| ./main` | перенос в конце не мешает |

## Некорректные данные (n/a)

| Ввод (stdin) | Ожидаемый результат | Команда | Причина |
|---|---|---|---|
| `b1.txt` | `n/a` | `echo "b1.txt" \| ./main` | в файле буква |
| `b2.txt` | `n/a` | `echo "b2.txt" \| ./main` | пустой файл |
| `b3.txt` | `n/a` | `echo "b3.txt" \| ./main` | после числа 3 стоит `x` |
| `nofile.txt` | `n/a` | `echo "nofile.txt" \| ./main` | файла нет |
| (пусто) | `n/a` | `./main < /dev/null` | путь не задан |

## Cppcheck, Clang-format

(те же блоки, что в других заданиях)

## Valgrind

```
echo "s1.txt" | valgrind --leak-check=full ./main
```

Обратите внимание: Valgrind запускается уже на скомпилированном файле.