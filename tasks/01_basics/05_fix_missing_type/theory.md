
<summary><b> Разбор задания</b></summary>


```c
#include <stdio.h>

int main(void)
{
    int x = 0; pi = 3.141;

    scanf("%d", &x);
    printf("%.2f", pi * x);

    return 0;
}
```


| № | Строка → исправление | Что | Тип ошибки |
|---|---|---|---|
| 1 | `int x = 0; pi = 3.141;`<br>↓<br>`int x = 0; double pi = 3.141;` | `pi` объявлена без типа — `pi` «необъявленная» | Ошибка компиляции |

---
В более сложных заданиях будет проверка на правильный ввод данных, поэтому советую привыкать к её реализации
```c 
if (scanf("%d", &x) != 1) 
```

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
echo 2 | valgrind --leak-check=full ./main
```

