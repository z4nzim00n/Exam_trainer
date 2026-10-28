# Команды на экзамене

## 1. Компиляция
```bash
gcc -Wall -Wextra -Werror -std=c11 main.c -o main
```

Если в коде есть `math.h` (sqrt, round, M_PI и т.п.): `-lm` в самый конец, а `-std=c11` убрать, с ним не виден `M_PI`:
```bash
gcc -Wall -Wextra -Werror main.c -o main -lm
```

`-std=c11` лучше не пропускать: он строже. Если собралось с ним, без него почти всегда соберётся тоже, а наоборот не гарантировано.

## 2. Cppcheck
```bash
cppcheck --enable=all --suppress=missingIncludeSystem main.c
```

Не помнишь имя после `--suppress=`? Запусти `cppcheck --enable=all main.c`: в лишней строке про include в конце, в `[скобках]`, будет нужное имя. Запоминать надо только `--suppress=`.

## 3. Valgrind
```bash
valgrind --leak-check=full ./main
```
