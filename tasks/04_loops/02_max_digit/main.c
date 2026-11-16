#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("n/a");
        return 0;
    }

    if (n < 0) {
        n = -n;
    }

    int c;
    while ((c = getchar()) != '\n') {
        if (c != '\0' && c != '\n') {
            printf("n/a");
            return 0;
        }
    }

    int max = 0;
    while (n != 0) {
        if (n % 10 > max) {
            max = n % 10;
        }
        n = n / 10;
    }

    printf("%d", max);

    return 0;
}
