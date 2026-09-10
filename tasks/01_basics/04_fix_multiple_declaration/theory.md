
<summary><b> Разбор задания</b></summary>


```c
#include <stdio.h>

int main(void)
{
    int left = 2, int right = 1;

    scanf("%d %d", &left, &right);
    printf("%d", left * right);

    return 0;
}
```


| № | Строка → исправление | Что | Тип ошибки |
|---|---|---|---|
| 1 | `int left = 2, int right = 1;`<br>↓<br>`int left = 2, right = 1;` | `int` написан дважды — тип ставится один раз, а дальше после запятой только имена переменных | Ошибка компиляции |

---
В более сложных заданиях будет проверка на правильный ввод данных, поэтому советую привыкать к её реализации
```c 
if (scanf("%d %d", &left, &right) != 2) 
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
echo 2 2 | valgrind --leak-check=full ./main
```

