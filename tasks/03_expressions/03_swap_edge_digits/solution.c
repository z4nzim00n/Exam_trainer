#include <stdio.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    int value;
    if (n < 0) {
        value = -n;
    } else {
        value = n;
    }

    int last = value % 10;
    value = value / 10;
    int middle = value % 10;
    value = value / 10;
    int first = value % 10;

    if (n < 0) {
        putchar('-');
    }

    printf("%d%d%d", last, middle, first);

    return 0;
}
