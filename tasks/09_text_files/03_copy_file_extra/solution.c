#include <stdio.h>
#include <string.h>

int main(void) {
    char source_path[256];
    char destination_path[256];
    int current_char;
    int error = 0;

    if (fgets(source_path, sizeof(source_path), stdin) == NULL) {
        printf("n/a");
        return 0;
    }

    size_t source_length = strlen(source_path);

    if (source_length == 0 || source_path[source_length - 1] != '\n') {
        printf("n/a");
        return 0;
    }

    source_path[source_length - 1] = '\0';

    if (source_path[0] == '\0') {
        printf("n/a");
        return 0;
    }

    if (fgets(destination_path, sizeof(destination_path), stdin) == NULL) {
        printf("n/a");
        return 0;
    }

    size_t destination_length = strlen(destination_path);

    if (destination_length == 0 || destination_path[destination_length - 1] != '\n') {
        printf("n/a");
        return 0;
    }

    destination_path[destination_length - 1] = '\0';

    if (destination_path[0] == '\0' || strcmp(source_path, destination_path) == 0) {
        printf("n/a");
        return 0;
    }

    FILE *source_file = fopen(source_path, "r");

    if (source_file == NULL) {
        printf("n/a");
        return 0;
    }

    FILE *destination_file = fopen(destination_path, "w");

    if (destination_file == NULL) {
        fclose(source_file);
        printf("n/a");
        return 0;
    }

    while ((current_char = fgetc(source_file)) != EOF) {
        if (fputc(current_char, destination_file) == EOF) {
            error = 1;
            break;
        }
    }

    if (ferror(source_file)) {
        error = 1;
    }

    if (fclose(source_file) != 0) {
        error = 1;
    }

    if (fclose(destination_file) != 0) {
        error = 1;
    }

    if (error) {
        printf("n/a");
    }

    return 0;
}