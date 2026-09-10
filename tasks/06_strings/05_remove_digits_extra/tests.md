# EXAM_08_06. Удаление цифр — Тесты

## Компиляция

Собственное решение:

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

Эталонное решение:

```bash
gcc -Wall -Wextra -Werror -std=c11 solution.c -o main
```

Комментированная версия:

```bash
gcc -Wall -Wextra -Werror -std=c11 solution_commented.c -o main
```

> Собирайте только один файл за раз: каждый содержит собственную функцию `main`.

## Валидные данные

| Вход | Результат | Команда | Пояснение |
| --- | --- | --- | --- |
| `a1b23c` | `abc` | `printf 'a1b23c\n' \| ./main` | Цифры между буквами |
| `School21` | `School` | `printf 'School21\n' \| ./main` | Цифры в конце |
| `Hello, World!` | `Hello, World!` | `printf 'Hello, World!\n' \| ./main` | Цифр нет |
| `1a2-b3!` | `a-b!` | `printf '1a2-b3!\n' \| ./main` | Знаки препинания сохраняются |
| `-12.5` | `-.` | `printf '%s\n' '-12.5' \| ./main` | Минус и точка не являются цифрами |
| `0123456789` | Пустой вывод | `printf '0123456789\n' \| ./main` | Удаляются все десять цифр |
| `0a9` | `a` | `printf '0a9\n' \| ./main` | Границы диапазона цифр |

«Пустой вывод» означает отсутствие любых символов, включая перевод строки.

## Важные случаи

В этой таблице вход и результат записаны как строковые литералы: кавычки не входят в данные, `\n` обозначает перевод строки.

| Вход | Результат | Команда | Пояснение |
| --- | --- | --- | --- |
| `"\n"` | `""` | `printf '\n' \| ./main` | Пустая строка |
| Пустой ввод | `""` | `./main < /dev/null` | EOF до первого символа |
| `"a\n"` | `"a"` | `printf 'a\n' \| ./main` | Одна буква |
| `"7\n"` | `""` | `printf '7\n' \| ./main` | Одна цифра |
| `"   \n"` | `"   "` | `printf '   \n' \| ./main` | Все пробелы сохраняются |
| `"a 123 b\n"` | `"a  b"` | `printf 'a 123 b\n' \| ./main` | Пробелы после удаления цифр не объединяются |
| `" 1a2 \n"` | `" a "` | `printf ' 1a2 \n' \| ./main` | Пробелы по краям сохраняются |
| `"a1b2"` | `"ab"` | `printf 'a1b2' \| ./main` | Завершение по EOF |
| `"/09:\n"` | `"/:"` | `printf '/09:\n' \| ./main` | Символы рядом с диапазоном цифр в ASCII |

## Проверка точного вывода

Посмотреть байты результата:

```bash
printf 'a 123 b\n' | ./main | od -An -t x1
```

Ожидается:

```text
61 20 20 62
```

Это символы `a`, два пробела и `b`.

Байта `0a` в конце быть не должно.

Проверка строки только из цифр:

```bash
printf '0123456789\n' | ./main | wc -c
```

Ожидаемое количество байтов:

```text
0
```

## Автоматическая проверка

Запускайте после компиляции из папки задания. Требуется Python 3.

```bash
python3 - <<'PY'
import subprocess

tests = [
    (b"a1b23c\n", b"abc"),
    (b"School21\n", b"School"),
    (b"Hello, World!\n", b"Hello, World!"),
    (b"1a2-b3!\n", b"a-b!"),
    (b"-12.5\n", b"-."),
    (b"0123456789\n", b""),
    (b"0a9\n", b"a"),
    (b"\n", b""),
    (b"", b""),
    (b"a\n", b"a"),
    (b"7\n", b""),
    (b"   \n", b"   "),
    (b"a 123 b\n", b"a  b"),
    (b" 1a2 \n", b" a "),
    (b"a1b2", b"ab"),
    (b"/09:\n", b"/:"),
    (b"a" * 100 + b"\n", b"a" * 100),
    (b"1" * 100 + b"\n", b""),
    (b"a1" * 50 + b"\n", b"a" * 50),
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

Последние три теста проверяют строки максимальной допустимой длины — 100 символов.

## Cppcheck

Статический анализ:

```bash
cppcheck --enable=all --suppress=missingIncludeSystem main.c
```

## Clang-format

Проверка стиля:

```bash
clang-format -n -Werror main.c
```

Автоматическое форматирование:

```bash
clang-format -i main.c
```

## Valgrind

Сборка с отладочной информацией:

```bash
gcc -Wall -Wextra -Werror -std=c11 -g main.c -o main
```

Проверка:

```bash
printf 'a 123 b\n' | valgrind --leak-check=full --track-origins=yes ./main
```

Дополнительные случаи:

```bash
printf '0123456789\n' | valgrind --leak-check=full --track-origins=yes ./main
```

```bash
valgrind --leak-check=full --track-origins=yes ./main < /dev/null
```

> Valgrind запускается на скомпилированной программе. Эталон не выделяет динамическую память самостоятельно.