# EXAM_08_01. Студенты выше среднего балла — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Валидные данные

| Вход | Результат | Пояснение |
| --- | --- | --- |
| `3\nAndrey\n15\nSergey\n20\nAnton\n10\n` | `Sergey` | Пример из условия |
| `4\nAlice\n50\nBob\n80\nCarol\n60\nDave\n90\n` | `Bob, Dave` | Двое выше среднего 70 |
| `3\nA\n10\nB\n10\nC\n10\n` | (пустой вывод) | Все равны среднему |
| `1\nOne\n50\n` | (пустой вывод) | Один студент — он равен «среднему» |
| `2\nA\n10\nB\n20\n` | `B` | Один выше среднего 15 |

## Команды запуска

```bash
printf '3\nAndrey\n15\nSergey\n20\nAnton\n10\n' | ./main
```

Ожидается:

```text
Sergey
```

```bash
printf '4\nAlice\n50\nBob\n80\nCarol\n60\nDave\n90\n' | ./main
```

Ожидается:

```text
Bob, Dave
```

## Важные случаи

| Вход | Результат | Пояснение |
| --- | --- | --- |
| `3\nA\n10\nB\n11\nC\n12\n` | `C` | Среднее 11.0, строго выше только C (12) |
| `3\nA\n10\nB\n10\nC\n11\n` | `C` | Среднее 10.33..., выше — C (11) |
| `2\nName With Spaces\n80\nAnother Name\n60\n` | `Name With Spaces` | Имена с пробелами |
| `3\nA\n100\nB\n0\nC\n50\n` | `A` | Крайние значения оценок |

Проверка на дробное среднее:

```bash
printf '3\nA\n10\nB\n10\nC\n11\n' | ./main
```

Ожидается:

```text
C
```

Если решение использует целочисленное деление, среднее будет 10 (вместо 10.33), и студент B тоже попадёт в вывод — это ошибка.

## Проверка формата вывода

Проверить, что нет завершающего перевода строки:

```bash
printf '3\nAndrey\n15\nSergey\n20\nAnton\n10\n' | ./main | od -An -t x1
```

Ожидается:

```text
53 65 72 67 65 79
```

Это `Sergey`. Байта `0a` в конце быть не должно.

Проверить формат разделителя (запятая с пробелом):

```bash
printf '4\nAlice\n50\nBob\n80\nCarol\n60\nDave\n90\n' | ./main | od -An -c
```

Ожидается:

```text
   B   o   b   ,       D   a   v   e
```

Между именами `,` и пробел. После `Dave` — конец вывода.

### Cppcheck

```bash
cppcheck --enable=all --suppress=missingIncludeSystem main.c
```

### Clang-format

```bash
clang-format -n -Werror main.c
```

### Valgrind

Проверка утечек памяти — обязательна, потому что мы выделяем массив через `malloc`:

```bash
printf '3\nAndrey\n15\nSergey\n20\nAnton\n10\n' | valgrind --leak-check=full ./main
```

Ожидается:

```text
All heap blocks were freed -- no leaks are possible
```