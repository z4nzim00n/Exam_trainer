/*
 * EXAM_09_07. Вывод файла.
 *
 * Самая простая работа с файлом: открыть, прочитать всё
 * по одному символу, закрыть.
 */

#include <stdio.h>

int main(void) {
    char path[256];

    /* Читаем путь к файлу. У path нет &: имя массива уже адрес. */
    if (scanf("%255s", path) != 1) {
        printf("n/a");
        return 0;
    }

    /* "r" — открыть для чтения. Если файла нет, fopen вернёт NULL. */
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("n/a");
        return 0;
    }

    /*
     * fgetc читает один символ и возвращает его код или EOF, когда файл кончился.
     * Переменная int, а не char: EOF не помещается в char.
     */
    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c); /* печатаем символ как есть */
    }

    /* Каждый открытый файл нужно закрыть. */
    fclose(file);

    return 0;
}