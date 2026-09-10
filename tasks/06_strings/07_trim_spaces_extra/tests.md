# EXAM_07_01. Удаление лишних пробелов — Тесты

## Компиляция

Для проверки собственного решения:

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

Для проверки эталона:

```bash
gcc -Wall -Wextra -Werror -std=c11 solution.c -o main
```

Для проверки комментированной версии:

```bash
gcc -Wall -Wextra -Werror -std=c11 solution_commented.c -o main
```

> Это отдельные программы. Собирайте только один файл за раз.

## Валидные данные

В таблицах вход записан как строковый литерал: кавычки не являются частью входа, а `\n` обозначает перевод строки.

| Вход | Результат | Команда | Пояснение |
| --- | --- | --- | --- |
| `"Hello world\n"` | `Hello world` | `printf 'Hello world\n' \| ./main` | Одиночный пробел сохраняется |
| `"Hello    world\n"` | `Hello world` | `printf 'Hello    world\n' \| ./main` | Несколько пробелов заменяются одним |
| `"   Hello\n"` | `Hello` | `printf '   Hello\n' \| ./main` | Начальные пробелы удаляются |
| `"Hello   \n"` | `Hello` | `printf 'Hello   \n' \| ./main` | Конечные пробелы удаляются |
| `"   Hello,    World!   \n"` | `Hello, World!` | `printf '   Hello,    World!   \n' \| ./main` | Все правила одновременно |
| `"  1   2     3  \n"` | `1 2 3` | `printf '  1   2     3  \n' \| ./main` | Цифры сохраняются |
| `"T e x t\n"` | `T e x t` | `printf 'T e x t\n' \| ./main` | Одиночные пробелы между буквами сохраняются |
| `"  Hi,   C!  21?  \n"` | `Hi, C! 21?` | `printf '  Hi,   C!  21?  \n' \| ./main` | Регистр и знаки препинания не меняются |

## Важные случаи

Обозначение «пустой вывод» означает отсутствие любых символов, включая пробелы и переводы строк.

| Вход | Результат | Команда | Пояснение |
| --- | --- | --- | --- |
| `"\n"` | Пустой вывод | `printf '\n' \| ./main` | Пустая строка |
| `"     \n"` | Пустой вывод | `printf '     \n' \| ./main` | Только пробелы |
| `"a\n"` | `a` | `printf 'a\n' \| ./main` | Один символ |
| `" a \n"` | `a` | `printf ' a \n' \| ./main` | Один символ между пробелами |
| `"abc\n"` | `abc` | `printf 'abc\n' \| ./main` | Пробелов нет |
| `"  a   b  "` | `a b` | `printf '  a   b  ' \| ./main` | Ввод заканчивается EOF, без `\n` |
| Пустой ввод | Пустой вывод | `./main < /dev/null` | EOF до первого символа |
| `"a  b\nc  d\n"` | `a b` | `printf 'a  b\nc  d\n' \| ./main` | Обрабатывается только первая строка |

> Табуляции и символы `'\r'` исключены условием. Проверять их как обязательные случаи задачи не нужно.

## Как увидеть лишние пробелы и переносы

При обычном запуске результат может сливаться с приглашением терминала: программа не выводит завершающий перенос строки.

Посмотреть точные байты результата:

```bash
printf '  a   b  \n' | ./main | od -An -t x1
```

Ожидаемые байты:

```text
61 20 62
```

Здесь:

- `61` — символ `a`;
- `20` — пробел;
- `62` — символ `b`.

В конце не должно быть дополнительного `20` или байта `0a`, обозначающего перевод строки.

Проверка пустого вывода:

```bash
printf '     \n' | ./main | wc -c
```

Ожидаемое количество байтов:

```text
0
```

## Автоматическая проверка

Следующий скрипт запускается из папки задания после компиляции. Требуется Python 3.

Он сравнивает результат побайтово, поэтому замечает лишние пробелы и переводы строк.

```bash
python3 - <<'PY'
import subprocess

tests = [
    (b"Hello world\n", b"Hello world"),
    (b"Hello    world\n", b"Hello world"),
    (b"   Hello\n", b"Hello"),
    (b"Hello   \n", b"Hello"),
    (b"   Hello,    World!   \n", b"Hello, World!"),
    (b"  1   2     3  \n", b"1 2 3"),
    (b"T e x t\n", b"T e x t"),
    (b"  Hi,   C!  21?  \n", b"Hi, C! 21?"),
    (b"\n", b""),
    (b"     \n", b""),
    (b"a\n", b"a"),
    (b" a \n", b"a"),
    (b"abc\n", b"abc"),
    (b"  a   b  ", b"a b"),
    (b"", b""),
    (b"a  b\nc  d\n", b"a b"),
    (b" " * 10000 + b"a" + b" " * 10000 + b"b   \n", b"a b"),
]

failed = 0

for number, (data, expected) in enumerate(tests, 1):
    result = subprocess.run(
        ["./main"],
        input=data,
        capture_output=True,
        timeout=5,
    )

    ok = result.returncode == 0 and result.stdout == expected
    print(f"Тест {number}: {'OK' if ok else 'FAIL'}")

    if not ok:
        failed += 1
        print(f"  Ожидалось: {expected!r}")
        print(f"  Получено:  {result.stdout!r}")
        print(f"  Код завершения: {result.returncode}")
        print(f"  stderr: {result.stderr!r}")

print(f"Пройдено: {len(tests) - failed}/{len(tests)}")
raise SystemExit(1 if failed else 0)
PY
```

Последний тест проверяет длинную строку. Условие не задаёт ограничение её длины.

## Cppcheck

Статический анализ кода:

```bash
cppcheck --enable=all --suppress=missingIncludeSystem main.c
```

Помогает найти потенциальные ошибки и подозрительные места в исходнике.

## Clang-format

Проверка стиля по настройкам проекта:

```bash
clang-format -n -Werror main.c
```

Автоматическое форматирование:

```bash
clang-format -i main.c
```

## Valgrind

Для более удобной диагностики соберите программу с отладочной информацией:

```bash
gcc -Wall -Wextra -Werror -std=c11 -g main.c -o main
```

Проверка обычной строки:

```bash
printf '   Hello,    World!   \n' | valgrind --leak-check=full --track-origins=yes ./main
```

Проверка строки только из пробелов:

```bash
printf '     \n' | valgrind --leak-check=full --track-origins=yes ./main
```

Проверка пустого ввода:

```bash
valgrind --leak-check=full --track-origins=yes ./main < /dev/null
```

> Valgrind запускается на скомпилированной программе. Эталонное решение не выделяет динамическую память самостоятельно, но проверка всё равно полезна для поиска ошибок работы с памятью в собственной реализации.