# EXAM_09_09. Подсчёт предложений — Тесты

## Компиляция

```
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

## Подготовка тестовых файлов

```
printf 'what???\n' > a1.txt
printf 'Test!? Yes!\n' > a2.txt
printf 'Hello world.\nHow are you?\nFine!\n' > a3.txt
printf 'no end\n' > a4.txt
printf '...!!!\n' > a5.txt
printf 'Wait... what?! Really?!\n' > a6.txt
printf '1.\n2!\n' > a7.txt
printf 'Hello\nworld.\n' > a8.txt
printf '' > a9.txt
printf 'S.M.A.R.T. Smart smart! Test test....\n' > a10.txt
```

## Валидные данные

| Ввод (stdin) | Содержимое файла | Результат | Команда | Пояснение |
|---|---|---|---|---|
| `a1.txt` | `what???` | `1` | `echo "a1.txt" \| ./main` | группа знаков считается один раз |
| `a2.txt` | `Test!? Yes!` | `2` | `echo "a2.txt" \| ./main` | пример из условия |
| `a3.txt` | три строки с `.` `?` `!` | `3` | `echo "a3.txt" \| ./main` | по предложению в строке |
| `a4.txt` | `no end` | `0` | `echo "a4.txt" \| ./main` | нет знака конца |
| `a5.txt` | `...!!!` | `0` | `echo "a5.txt" \| ./main` | нет букв и цифр |
| `a6.txt` | `Wait... what?! Really?!` | `3` | `echo "a6.txt" \| ./main` | смешанные группы знаков |
| `a7.txt` | `1.`<br>`2!` | `2` | `echo "a7.txt" \| ./main` | цифры тоже содержимое |
| `a8.txt` | `Hello`<br>`world.` | `1` | `echo "a8.txt" \| ./main` | предложение занимает две строки |
| `a9.txt` | пустой файл | `0` | `echo "a9.txt" \| ./main` | предложений нет |
| `a10.txt` | `S.M.A.R.T. Smart smart! Test test....` | `7` | `echo "a10.txt" \| ./main` | каждая точка после буквы считается концом (**требует сверки с условием**) |

## Некорректные данные (n/a)

| Ввод (stdin) | Ожидаемый результат | Команда | Причина |
|---|---|---|---|
| `nofile.txt` | `n/a` | `echo "nofile.txt" \| ./main` | файла нет |
| (пусто) | `n/a` | `./main < /dev/null` | путь не задан |

## Cppcheck

Статический анализ кода. Нужен, чтобы найти потенциальные ошибки и подозрительные места в исходнике, которые компилятор может не заметить.

```
cppcheck --enable=all --suppress=missingIncludeSystem main.c
```

## Clang-format

Проверка стиля и форматирования кода.

```
clang-format -n -Werror main.c
```

Если нужно автоматически отформатировать файл:

```
clang-format -i main.c
```

## Valgrind

Проверка ошибок работы с памятью и утечек памяти. Незакрытый файл будет показан как утечка.

```
echo "a2.txt" | valgrind --leak-check=full ./main
```

Обратите внимание: Valgrind запускается уже на скомпилированном файле.