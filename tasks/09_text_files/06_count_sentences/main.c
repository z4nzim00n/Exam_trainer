#include <stdio.h>

int main(void) {
    char path[256];
    int shift;

    if (scanf("%255s %d", path, &shift) != 2) {
        printf("n/a");
        return 0;
    }

    FILE* file = fopen(path, "r+");
    if (file == NULL) {
        printf("n/a");
        return 0;
    }

    char text[1001];
    size_t n = fread(text, 1, 1000, file);

    if (n == 0 || n == 1000) {
        printf("n/a");
        fclose(file);
        return 0;
    }

    shift = shift % 26;
    if (shift < 0) {
        shift += 26;
    }

    for (size_t i = 0; i < n; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' + shift) % 26;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' + shift) % 26;
        }
    }

    rewind(file);
    fwrite(text, 1, n, file);
    fclose(file);

    return 0;
}