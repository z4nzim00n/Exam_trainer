#include <stdio.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("n/a");
        return 0;
    }

    int product = 1;
    int has_odd = 0;
    int digit;

    do {
        digit = n % 10;
        if (digit < 0) {
            digit = -digit;
        }

        if (digit % 2 != 0) {
            product *= digit;
            has_odd = 1;
        }
        n /= 10;
    } while (n != 0);

    if (has_odd) {
        printf("%d", product);
    } else {
        printf("0");
    }

    return 0;
}