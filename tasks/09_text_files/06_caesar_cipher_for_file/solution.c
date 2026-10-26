#include <stdio.h>

int main(void) {
    char path[256];
    int shift;

    if (scanf("%255s %d", path, &shift) != 2) {
        printf("n/a");
        return 0;
    }

    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("n/a");
        return 0;
    }

    shift = shift % 26;
    if (shift < 0) {
        shift += 26;
    }

    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + shift) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + shift) % 26;
        }
        putchar(c);
    }

    fclose(file);

    return 0;
}