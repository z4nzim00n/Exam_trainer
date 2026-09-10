# EXAM_07_02. Шифр Цезаря — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

Для проверки эталона замените `main.c` на `solution.c` или `solution_commented.c`. Собирайте файлы по отдельности.

## Проверочные случаи

В командах `\n` обозначает перевод строки. Кавычки оболочки не входят во входные данные.

| Команда | Результат | Пояснение |
| --- | --- | --- |
| `printf '3\nHello, World!\n' \| ./main` | `Khoor, Zruog!` | Обычное шифрование |
| `printf '1\nxyz XYZ 123\n' \| ./main` | `yza YZA 123` | Переход через конец алфавита |
| `printf '0\nSchool21\n' \| ./main` | `School21` | Нулевой сдвиг |
| `printf '25\nAbc XYZ\n' \| ./main` | `Zab WXY` | Максимальный сдвиг |
| `printf '13\nHello\n' \| ./main` | `Uryyb` | Сдвиг на половину алфавита |
| `printf '3\n123 !?-_\n' \| ./main` | `123 !?-_` | Небуквенные символы не меняются |
| `printf '3\n\n' \| ./main` | Пустой вывод | Пустой текст |
| `printf '2\nAz' \| ./main` | `Cb` | Текст заканчивается EOF |

Данные вне диапазона сдвига `0..25` не входят в условия задачи.

## Точная проверка пробелов и переноса

```bash
printf '1\n  a Z  \n' | ./main | od -An -t x1
```

Ожидаемые байты:

```text
20 20 62 20 41 20 20
```

Начальные и конечные пробелы сохраняются. Байта `0a` в результате быть не должно.

Проверка пустого результата:

```bash
printf '3\n\n' | ./main | wc -c
```

Ожидается `0`.

## Cppcheck

```bash
cppcheck --enable=all --suppress=missingIncludeSystem main.c
```

Статический анализ исходного кода.

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

```bash
printf '3\nHello, World!\n' | valgrind --leak-check=full --track-origins=yes ./main
```

Valgrind запускается на скомпилированной программе. Эталон не выделяет динамическую память самостоятельно.