# EXAM_06_15. Идентификатор — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Ответ Yes

| Вход | Результат | Команда | Пояснение |
| --- | --- | --- | --- |
| `my_var1` | `Yes` | `echo "my_var1" \| ./main` | пример из условия |
| `_` | `Yes` | `echo "_" \| ./main` | одно подчёркивание |
| `A` | `Yes` | `echo "A" \| ./main` | одна буква |
| `_a1B2` | `Yes` | `echo "_a1B2" \| ./main` | начинается с `_`, дальше буквы и цифры |
| `abc` (без `\n`) | `Yes` | `printf "abc" \| ./main` | конец ввода без переноса строки |

## Ответ No

| Вход | Результат | Команда | Причина |
| --- | --- | --- | --- |
| `1abc` | `No` | `echo "1abc" \| ./main` | начинается с цифры |
| `a-b` | `No` | `echo "a-b" \| ./main` | недопустимый символ `-` |
| `a b` | `No` | `echo "a b" \| ./main` | пробел внутри |
| `abc!` | `No` | `echo "abc!" \| ./main` | недопустимый символ в конце |
| пустая строка | `No` | `echo "" \| ./main` | нет ни одного символа |
| `привет` | `No` | `echo "привет" \| ./main` | не латинские буквы |

### Cppcheck

```bash
cppcheck --enable=all --suppress=missingIncludeSystem main.c
```

### Clang-format

```bash
clang-format -n -Werror main.c
```

Если нужно автоматически отформатировать файл:

```bash
clang-format -i main.c
```

### Valgrind

```bash
echo "my_var1" | valgrind --leak-check=full ./main
```

> Обратите внимание: Valgrind запускается уже на скомпилированном файле.