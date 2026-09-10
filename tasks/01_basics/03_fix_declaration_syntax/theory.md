
<summary><b>Разбор задания</b></summary>


```c
#include <stdio.h>

int main(void)
{
    int first = 3, second = 4;

    scanf("%d %d", &first, &second);
    printf("%d", first * second);

    return 0;
}
```


| № | Строка → исправление | Что | Тип ошибки |
|---|---|---|---|
| 1 | `int: first = 3, second = 4;`<br>↓<br>`int first = 3, second = 4;` | `int:` в C нельзя — это не объявление ни одной переменной (`first` и `second` не определены) | Ошибка компиляции |

---
В более сложных заданиях будет проверка на правильный ввод данных, поэтому советую привыкать к её реализации
```c 
if (scanf("%d %d", &first, &second) != 2) 
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

