#include <stdio.h>
#include <string.h>

int main(void) {
    // Пути к исходному файлу и файлу назначения.
    char source_path[256];
    char destination_path[256];

    // Текущий прочитанный символ.
    int current_char;

    // Флаг ошибки.
    int error = 0;

    // Читаем путь исходного файла.
    if (fgets(source_path, sizeof(source_path), stdin) == NULL) {
        printf("n/a");
        return 0;
    }

    // Проверяем длину пути и наличие '\n'.
    size_t source_length = strlen(source_path);

    if (source_length == 0 || source_path[source_length - 1] != '\n') {
        printf("n/a");
        return 0;
    }

    // Удаляем символ новой строки.
    source_path[source_length - 1] = '\0';

    // Проверяем, что путь не пустой.
    if (source_path[0] == '\0') {
        printf("n/a");
        return 0;
    }

    // Читаем путь файла назначения.
    if (fgets(destination_path, sizeof(destination_path), stdin) == NULL) {
        printf("n/a");
        return 0;
    }

    // Проверяем длину второго пути.
    size_t destination_length = strlen(destination_path);

    if (destination_length == 0 || destination_path[destination_length - 1] != '\n') {
        printf("n/a");
        return 0;
    }

    // Удаляем символ новой строки.
    destination_path[destination_length - 1] = '\0';

    // Проверяем пустой путь и совпадение путей.
    if (destination_path[0] == '\0' || strcmp(source_path, destination_path) == 0) {
        printf("n/a");
        return 0;
    }

    // Открываем исходный файл для чтения.
    FILE *source_file = fopen(source_path, "r");

    if (source_file == NULL) {
        printf("n/a");
        return 0;
    }

    // Открываем файл назначения для записи.
    // Если он существует, его содержимое будет удалено.
    FILE *destination_file = fopen(destination_path, "w");

    if (destination_file == NULL) {
        fclose(source_file);
        printf("n/a");
        return 0;
    }

    // Читаем исходный файл посимвольно.
    while ((current_char = fgetc(source_file)) != EOF) {

        // Записываем каждый символ в файл назначения.
        if (fputc(current_char, destination_file) == EOF) {
            error = 1;
            break;
        }
    }

    // Проверяем ошибку чтения исходного файла.
    if (ferror(source_file)) {
        error = 1;
    }

    // Закрываем исходный файл.
    if (fclose(source_file) != 0) {
        error = 1;
    }

    // Закрываем файл назначения.
    // Здесь также может обнаружиться ошибка записи.
    if (fclose(destination_file) != 0) {
        error = 1;
    }

    // Выводим ошибку, если копирование прошло не полностью.
    if (error) {
        printf("n/a");
    }

    return 0;
}