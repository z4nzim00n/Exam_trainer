#include <stdio.h>
#include <string.h>

int main(void) {
    // Буфер для хранения пути к файлу.
    char path[256];

    // Переменная для чтения символов из stdin.
    int current_char;

    // Флаг ошибки записи или чтения.
    int error = 0;

    // Читаем первую строку — путь к файлу.
    if (fgets(path, sizeof(path), stdin) == NULL) {
        printf("n/a");
        return 0;
    }

    // Определяем длину полученной строки.
    size_t path_length = strlen(path);

    // Проверяем, что строка заканчивается символом '\n'.
    // Если его нет, путь не поместился в буфер или строка некорректна.
    if (path_length == 0 || path[path_length - 1] != '\n') {
        printf("n/a");
        return 0;
    }

    // Убираем '\n', чтобы получить чистый путь к файлу.
    path[path_length - 1] = '\0';

    // Проверяем, что путь не пустой.
    if (path[0] == '\0') {
        printf("n/a");
        return 0;
    }

    // Открываем файл в режиме записи.
    // Если файл существует, его содержимое будет удалено.
    // Если файла нет, он будет создан.
    FILE* file = fopen(path, "w");

    if (file == NULL) {
        printf("n/a");
        return 0;
    }

    // Читаем оставшиеся символы из стандартного ввода.
    // EOF означает конец ввода.
    while ((current_char = getchar()) != EOF) {
        // Записываем текущий символ в файл.
        // Если запись не удалась, устанавливаем флаг ошибки.
        if (fputc(current_char, file) == EOF) {
            error = 1;
            break;
        }
    }

    // Проверяем, не произошла ли ошибка при чтении stdin.
    if (ferror(stdin)) {
        error = 1;
    }

    // Закрываем файл.
    // fclose также может обнаружить ошибку записи.
    if (fclose(file) != 0) {
        error = 1;
    }

    // Выводим сообщение об ошибке, если она произошла.
    if (error) {
        printf("n/a");
    }

    return 0;
}