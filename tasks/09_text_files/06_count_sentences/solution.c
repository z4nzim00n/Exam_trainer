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

    int count = 0;
    int has_text = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            has_text = 1;
        } else if (c == '.' || c == '!' || c == '?') {
            if (has_text) {
                count++;
                has_text = 0;
            }
        }
    }

    fclose(file);

    printf("%d", count);

    return 0;
}