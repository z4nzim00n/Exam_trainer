# EXAM_08_03. Студент с наивысшим баллом — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Валидные данные

| Вход | Результат | Команда |
| --- | --- | --- |
| `3\nAnton\n10\nSergey\n20\nAndrey\n15\n` | `Sergey 20` | `printf '3\nAnton\n10\nSergey\n20\nAndrey\n15\n' \| ./main` |
| `4\nAlice\n80\nBob\n90\nCarol\n90\nDave\n70\n` | `Bob 90` | `printf '4\nAlice\n80\nBob\n90\nCarol\n90\nDave\n70\n' \| ./main` |
| `1\nSolo\n50\n` | `Solo 50` | `printf '1\nSolo\n50\n' \| ./main` |
| `3\nA\n100\nB\n100\nC\n100\n` | `A 100` | `printf '3\nA\n100\nB\n100\nC\n100\n' \| ./main` |
| `2\nFirst\n0\nSecond\n1\n` | `Second 1` | `printf '2\nFirst\n0\nSecond\n1\n' \| ./main` |

## Проверка формата

```bash
printf '3\nAnton\n10\nSergey\n20\nAndrey\n15\n' | ./main | od -An -t x1
```

Ожидается: `53 65 72 67 65 79 20 32 30` (Sergey 20, без `0a` в конце).

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
printf '3\nAnton\n10\nSergey\n20\nAndrey\n15\n' | valgrind --leak-check=full ./main
```