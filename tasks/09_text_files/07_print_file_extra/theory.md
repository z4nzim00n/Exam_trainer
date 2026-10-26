# EXAM_09_07. Вывод файла — Тесты

## Компиляция

```
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Подготовка тестовых файлов

```
printf 'Hello' > f1.txt
printf 'Hello\nWorld' > f2.txt
printf 'a b,c 123!' > f3.txt
```

## Валидные данные

| Ввод (stdin) | Содержимое файла | Результат | Команда | Пояснение |
|---|---|---|---|---|
| `f1.txt` | `Hello` | `Hello` | `echo "f1.txt" \| ./main` | одна строка |
| `f2.txt` | `Hello`<br>`World` | `Hello`<br>`World` | `echo "f2.txt" \| ./main` | перенос внутри файла сохраняется |
| `f3.txt` | `a b,c 123!` | `a b,c 123!` | `echo "f3.txt" \| ./main` | пробелы и знаки без изменений |

## Некорректные данные (n/a)

| Ввод (stdin) | Ожидаемый результат | Команда | Причина |
|---|---|---|---|
| `nofile.txt` | `n/a` | `echo "nofile.txt" \| ./main` | файла нет |
| (пусто) | `n/a` | `./main < /dev/null` | путь не задан |

## Cppcheck, Clang-format

(те же блоки, что в других заданиях)

## Valgrind

Незакрытый файл будет показан как утечка.

```
echo "f2.txt" | valgrind --leak-check=full ./main
```

Обратите внимание: Valgrind запускается уже на скомпилированном файле.