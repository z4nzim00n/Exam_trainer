#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("n/a");
        return 0;
    }

    int negative = 0;
    if (n < 0) {
        negative = 1;
        n = -n;
    }

    int last = n % 10;
    n = n / 10;
    int mid = n % 10;
    n = n / 10;
    int first = n % 10;

    if (negative) putchar('-');
    printf("%d%d%d", last, mid, first);

    return 0;
}