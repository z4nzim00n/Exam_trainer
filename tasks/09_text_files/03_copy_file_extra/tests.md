# EXAM_09_03. Копирование файла — Тесты

## Компиляция

```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Подготовка файлов

```bash
printf 'Hello' > source1.txt
printf 'Hello\nWorld' > source2.txt
: > empty.txt
printf 'old content' > destination.txt
```

## Валидные данные

| Ввод (`stdin`) | Ожидаемый результат | Проверка |
|---|---|---|
| `source1.txt` затем `copy1.txt` | stdout пустой; `copy1.txt` = `Hello` | обычное копирование |
| `source2.txt` затем `copy2.txt` | stdout пустой; содержимое совпадает | перевод строки сохраняется |
| `empty.txt` затем `copy3.txt` | stdout пустой; файл назначения пустой | копирование пустого файла |
| `source1.txt` затем `destination.txt` | stdout пустой; старое содержимое заменено | перезапись назначения |

## Некорректные данные

| Ввод (`stdin`) | Результат | Причина |
|---|---|---|
| `missing.txt` затем `copy.txt` | `n/a` | исходного файла нет |
| `source1.txt` затем `source1.txt` | `n/a` | пути совпадают |
| только `source1.txt` | `n/a` | путь назначения не задан |
| пустой ввод | `n/a` | пути не заданы |
| `source1.txt` затем `/no/such/dir/copy.txt` | `n/a` | назначение невозможно создать |

## Ручная проверка

```bash
printf 'source2.txt\ncopy.txt\n' | ./main
cmp source2.txt copy.txt
```

Если `cmp` ничего не вывел и вернул код 0, файлы совпадают.
