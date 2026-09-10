
<summary> <b>Разбор задания</b> </summary>


```c
#include <stdio.h>

int main(void)
{
    int x = 205;
    printf("%05d", &x);

    return 0;
}
```


| № | Строка → исправление | Что | Тип ошибки |
|---|---|---|---|
| 1 | `printf("%05d", &x);`<br>↓<br>`printf("%d", x);` | В `printf` передаётся адрес `x` вместо самого значения. Кроме того, `%05d` выводит число с шириной 5 символов и нулями слева, а по условию нужно вывести именно `205` | Логическая ошибка |


И делать проверку на стиль
```bash
clang-format -n -Werror main.c
```
```
clang-format -i main.c
```


Также в README.md советуют проверять на утечку памяти. Перед этим нужно скомпилировать программу
```bash
gcc -Wall -Wextra -Werror main.c -o main
```
```bash
valgrind --leak-check=full ./main
```