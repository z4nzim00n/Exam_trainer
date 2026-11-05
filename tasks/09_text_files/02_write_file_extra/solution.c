#include <stdio.h>
#include <string.h>

int main(void) {
    char path[256];
    int current_char;
    int error = 0;

    if (fgets(path, sizeof(path), stdin) == NULL) {
        printf("n/a");
        return 0;
    }

    size_t path_length = strlen(path);

    if (path_length == 0 || path[path_length - 1] != '\n') {
        printf("n/a");
        return 0;
    }

    path[path_length - 1] = '\0';

    if (path[0] == '\0') {
        printf("n/a");
        return 0;
    }

    FILE* file = fopen(path, "w");

    if (file == NULL) {
        printf("n/a");
        return 0;
    }

    while ((current_char = getchar()) != EOF) {
        if (fputc(current_char, file) == EOF) {
            error = 1;
            break;
        }
    }

    if (ferror(stdin)) {
        error = 1;
    }

    if (fclose(file) != 0) {
        error = 1;
    }

    if (error) {
        printf("n/a");
    }

    return 0;
}