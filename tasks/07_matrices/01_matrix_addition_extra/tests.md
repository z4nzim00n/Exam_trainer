# EXAM_07_05. Сложение квадратных матриц — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

Для проверки эталона замените имя исходного файла на `solution.c` или `solution_commented.c`.

## Обычное сложение

```bash
printf '2\n1 2\n3 4\n5 6\n7 8\n' | ./main
```

Ожидается:

```text
6 8
10 12
```

## Матрицы из одного элемента

```bash
printf '1\n-5\n8\n' | ./main
```

Ожидается:

```text
3
```

## Взаимно противоположные элементы

```bash
printf '2\n1 -2\n0 4\n-1 2\n0 -4\n' | ./main
```

Ожидается:

```text
0 0
0 0
```

## Отрицательные значения

```bash
printf '2\n-1 -2\n-3 -4\n-5 -6\n-7 -8\n' | ./main
```

Ожидается:

```text
-6 -8
-10 -12
```

## Границы значений элементов

```bash
printf '2\n100 -100\n100 -100\n100 -100\n-100 100\n' | ./main
```

Ожидается:

```text
200 -200
0 0
```

## Максимальный размер

Требуется Python 3. Проверяются матрицы `10 x 10`, заполненные единицами и двойками.

```bash
python3 - <<'PY'
import subprocess

data = "10\n" + " ".join(["1"] * 100) + "\n"
data += " ".join(["2"] * 100) + "\n"
expected = "\n".join([" ".join(["3"] * 10)] * 10).encode()

result = subprocess.run(
    ["./main"], input=data.encode(), capture_output=True, timeout=5
)

assert result.returncode == 0
assert result.stdout == expected, repr(result.stdout)
print("OK")
PY
```

## Точный формат вывода

```bash
printf '2\n1 2\n3 4\n5 6\n7 8\n' | ./main | od -An -t x1
```

Ожидается:

```text
36 20 38 0a 31 30 20 31 32
```

Перенос `0a` есть только между строками. Конечных пробелов нет.

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
printf '2\n1 2\n3 4\n5 6\n7 8\n' | valgrind --leak-check=full --track-origins=yes ./main
```

> Ввод по условию корректен. Обязательного вывода `n/a` для некорректных данных в этом задании нет.