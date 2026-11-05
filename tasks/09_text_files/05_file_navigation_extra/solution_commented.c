#include <stdio.h>

int main(void) {
    // Путь к файлу.
    char path[256];

    // Позиция символа, который необходимо прочитать.
    long position;

    // Размер файла.
    long file_size;

    // Прочитанный символ.
    int current_char;

    // Получаем путь к файлу и позицию.
    if (scanf("%255s %ld", path, &position) != 2 || position < 0) {
        printf("n/a");
        return 0;
    }

    // Открываем файл для чтения.
    FILE *file = fopen(path, "r");

    if (file == NULL) {
        printf("n/a");
        return 0;
    }

    // Перемещаем указатель в конец файла.
    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        printf("n/a");
        return 0;
    }

    // Получаем текущую позицию указателя — размер файла.
    file_size = ftell(file);

    // Проверяем корректность размера и позиции.
    // Индексация начинается с нуля.
    if (file_size < 0 || position >= file_size) {
        fclose(file);
        printf("n/a");
        return 0;
    }

    // Перемещаем указатель на нужную позицию от начала файла.
    if (fseek(file, position, SEEK_SET) != 0) {
        fclose(file);
        printf("n/a");
        return 0;
    }

    // Считываем символ с выбранной позиции.
    current_char = fgetc(file);

    if (current_char == EOF) {
        fclose(file);
        printf("n/a");
        return 0;
    }

    // Закрываем файл.
    if (fclose(file) != 0) {
        printf("n/a");
        return 0;
    }

    // Выводим размер файла и числовой код символа.
    printf("%ld %d", file_size, current_char);

    return 0;
}