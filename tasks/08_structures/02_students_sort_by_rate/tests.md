# EXAM_08_02. Сортировка студентов по баллам — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Валидные данные

### Пример из условия

```bash
printf '3\nAnton\n10\nSergey\n20\nAndrey\n30\n' | ./main
```

Ожидается:

```text
Andrey 30
Sergey 20
Anton 10
```

### Одинаковые оценки — устойчивость сортировки

```bash
printf '4\nAlice\n75\nBob\n90\nCarol\n75\nDave\n60\n' | ./main
```

Ожидается:

```text
Bob 90
Alice 75
Carol 75
Dave 60
```

> Alice появилась раньше Carol, поэтому идёт выше при одинаковой оценке.

### Уже отсортированный список

```bash
printf '3\nA\n90\nB\n80\nC\n70\n' | ./main
```

Ожидается:

```text
A 90
B 80
C 70
```

### Обратный порядок

```bash
printf '3\nA\n10\nB\n20\nC\n30\n' | ./main
```

Ожидается:

```text
C 30
B 20
A 10
```

## Важные случаи

### Один студент

```bash
printf '1\nSolo\n50\n' | ./main
```

Ожидается:

```text
Solo 50
```

### Имена с пробелами

```bash
printf '2\nAndrey Ivanov\n80\nSergey Petrov\n70\n' | ./main
```

Ожидается:

```text
Andrey Ivanov 80
Sergey Petrov 70
```

### Все с одинаковой оценкой

```bash
printf '3\nA\n50\nB\n50\nC\n50\n' | ./main
```

Ожидается:

```text
A 50
B 50
C 50
```

> Порядок ввода сохраняется.

### Крайние значения

```bash
printf '3\nMax\n100\nMid\n50\nMin\n0\n' | ./main
```

Ожидается:

```text
Max 100
Mid 50
Min 0
```

## Проверка формата вывода

Проверить, что нет завершающего перевода строки:

```bash
printf '3\nAnton\n10\nSergey\n20\nAndrey\n30\n' | ./main | od -An -t x1 | tail -1
```

Последний байт должен быть кодом цифры (`30` — это `0`), а не `0a`.

Проверить формат строки:

```bash
printf '2\nName\n99\nOther\n50\n' | ./main | od -An -c
```

Ожидается:

```text
   N   a   m   e       9   9  \n   O   t   h   e   r       5   0
```

Между именем и оценкой — один пробел. Между студентами — `\n`. В конце — цифра, без `\n`.

### Cppcheck

```bash
cppcheck --enable=all --suppress=missingIncludeSystem main.c
```

### Clang-format

```bash
clang-format -n -Werror main.c
```

### Valgrind

Проверка утечек:

```bash
printf '3\nAnton\n10\nSergey\n20\nAndrey\n30\n' | valgrind --leak-check=full ./main
```

Ожидается:

```text
All heap blocks were freed -- no leaks are possible
```