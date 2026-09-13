# EXAM_08_04. Товары в корзине — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Валидные данные

### Пример из условия

```bash
printf '3\nApple\n50\n10\nBread\n30\n2\nMilk\n80\n3\n' | ./main
```

Ожидается:

```text
Apple 50 10 500
Bread 30 2 60
Milk 80 3 240
Total 800
```

### Один товар

```bash
printf '1\nPen\n10\n5\n' | ./main
```

Ожидается:

```text
Pen 10 5 50
Total 50
```

### Нулевая цена

```bash
printf '2\nFree\n0\n10\nPaid\n100\n1\n' | ./main
```

Ожидается:

```text
Free 0 10 0
Paid 100 1 100
Total 100
```

### Большие числа

```bash
printf '1\nExpensive\n10000\n10000\n' | ./main
```

Ожидается:

```text
Expensive 10000 10000 100000000
Total 100000000
```

> 10^8 помещается в int, но при 100 таких товарах будет 10^10 — нужен long long.

## Проверка формата

```bash
printf '1\nPen\n10\n5\n' | ./main | od -An -t x1
```

Последний байт должен быть `30` (цифра `0` из `50`), не `0a`.

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
printf '3\nApple\n50\n10\nBread\n30\n2\nMilk\n80\n3\n' | valgrind --leak-check=full ./main
```