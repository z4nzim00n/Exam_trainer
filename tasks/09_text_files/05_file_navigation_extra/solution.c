#include <stdio.h>

int main(void) {
    char path[256];
    long position;
    long file_size;
    int current_char;

    if (scanf("%255s %ld", path, &position) != 2 || position < 0) {
        printf("n/a");
        return 0;
    }

    FILE *file = fopen(path, "r");

    if (file == NULL) {
        printf("n/a");
        return 0;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        printf("n/a");
        return 0;
    }

    file_size = ftell(file);

    if (file_size < 0 || position >= file_size) {
        fclose(file);
        printf("n/a");
        return 0;
    }

    if (fseek(file, position, SEEK_SET) != 0) {
        fclose(file);
        printf("n/a");
        return 0;
    }

    current_char = fgetc(file);

    if (current_char == EOF) {
        fclose(file);
        printf("n/a");
        return 0;
    }

    if (fclose(file) != 0) {
        printf("n/a");
        return 0;
    }

    printf("%ld %d", file_size, current_char);

    return 0;
}