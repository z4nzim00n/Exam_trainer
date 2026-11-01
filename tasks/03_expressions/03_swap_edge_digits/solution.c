#include <stdio.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    int negative_sign = 0;
    if (n < 0) {
        n = -n;
        negative_sign = 1;
    }

    int last = n % 10;
    n = n / 10;
    int middle = n % 10;
    n = n / 10;
    int first = n % 10;

    if (negative_sign) {
        putchar('-');
    }

    printf("%d%d%d", last, middle, first);

    return 0;
}
