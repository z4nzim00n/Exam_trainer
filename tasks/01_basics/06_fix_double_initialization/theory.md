
<summary><b> Разбор задания</b></summary>


```c
#include <stdio.h>

int main(void)
{
    int value = 1;
    double pi = "3.141";

    scanf("%d", &value);
    printf("%.2f", value * pi);

    return 0;
}
```


| № | Строка → исправление | Что | Тип ошибки |
|---|---|---|---|
| 1 | `double pi = "3.141";`<br>↓<br>`double pi = 3.141;` | `"3.141"` в кавычках — строка (`const char*`), и `double` её не принимает. Убираем кавычки | Ошибка компиляции |

---
В более сложных заданиях будет проверка на правильный ввод данных, поэтому советую привыкать к её реализации
```c 
if (scanf("%d", &value) != 1) 
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

