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
    int c = fgetc(file);

    while (c != EOF) {
        long long total = 0;
        long long number = 0;
        int sign = 1;
        int digits = 0;
        int ok = 1;

        while (c != EOF && c != '\n') {
            if (c >= '0' && c <= '9') {
                digits++;
                if (digits > 9) {
                    ok = 0;
                } else {
                    number = number * 10 + (c - '0');
                }
            } else if ((c == '+' || c == '-') && digits > 0) {
                total += sign * number;
                sign = (c == '+') ? 1 : -1;
                number = 0;
                digits = 0;
            } else {
                ok = 0;
            }
            c = fgetc(file);
        }

        if (digits == 0) {
            ok = 0;
        }
        total += sign * number;

        if (count > 0) {
            printf(", ");
        }
        if (ok) {
            printf("%lld", total);
        } else {
            printf("n/a");
        }
        count++;

        if (c == '\n') {
            c = fgetc(file);
        }
    }

    fclose(file);

    if (count == 0) {
        printf("n/a");
    }

    return 0;
}