# EXAM_08_05. Книги: сортировка по году и названию — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Валидные данные

### Пример из условия

```bash
printf '4\nBrave New World\n1932\n1984\n1949\nAnimal Farm\n1945\nFahrenheit 451\n1953\n' | ./main
```

Ожидается:

```text
1932 Brave New World
1945 Animal Farm
1949 1984
1953 Fahrenheit 451
```

### Одинаковый год — сортировка по названию

```bash
printf '3\nZoo\n2000\nApple\n2000\nMango\n2000\n' | ./main
```

Ожидается:

```text
2000 Apple
2000 Mango
2000 Zoo
```

### Одна книга

```bash
printf '1\nSolo\n2020\n' | ./main
```

Ожидается:

```text
2020 Solo
```

### Уже отсортировано

```bash
printf '2\nA\n1900\nB\n2000\n' | ./main
```

Ожидается:

```text
1900 A
2000 B
```

### Обратный порядок

```bash
printf '2\nB\n2000\nA\n1900\n' | ./main
```

Ожидается:

```text
1900 A
2000 B
```

## Проверка формата

```bash
printf '1\nSolo\n2020\n' | ./main | od -An -t x1
```

Последний байт — не `0a`.

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
printf '3\nZoo\n2000\nApple\n2000\nMango\n2000\n' | valgrind --leak-check=full ./main
```