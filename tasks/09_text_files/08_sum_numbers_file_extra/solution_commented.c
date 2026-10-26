/*
* EXAM_09_08. Сумма чисел из файла.
 *
 * fscanf работает как scanf, только читает из файла.
 * Читаем числа по одному, пока они не кончатся, и складываем.
 */

#include <stdio.h>

int main(void) {
    char path[256];

    if (scanf("%255s", path) != 1) {
        printf("n/a");
        return 0;
    }

    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("n/a");
        return 0;
    }

    long sum = 0;
    int count = 0; /* сколько чисел прочитали */
    int number;
    int status; /* что вернул fscanf */

    /*
     * fscanf возвращает:
     *   1   — число прочитано;
     *   EOF — файл кончился;
     *   0   — дальше стоит не число (например, буква).
     * Пробелы и переводы строк между числами fscanf пропускает сам.
     */
    while ((status = fscanf(file, "%d", &number)) == 1) {
        sum += number;
        count++;
    }

    fclose(file);

    /*
     * Цикл остановился. Если не на EOF, значит встретилось не число — ошибка.
     * Если чисел не было вообще (пустой файл) — тоже ошибка.
     */
    if (status != EOF || count == 0) {
        printf("n/a");
    } else {
        printf("%ld", sum);
    }

    return 0;
}