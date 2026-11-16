#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("n/a");
        return 0;
    }

    while (n != 0 && n % 10 == 0) {
        n = n / 10;
    }

    if (n == 0) {
        printf("0");
        return 0;
    }

    while (n != 0) {
        printf("%d", n % 10);
        n = n / 10;
    }

    return 0;
}