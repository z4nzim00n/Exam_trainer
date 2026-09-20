#include <stdio.h>

int main(void) {
    int n;
    int c;

    if (scanf("%d", &n) != 1) {
        printf("n/a");
        return 0;
    }

    while ((c = getchar()) != EOF && c != '\n') {
        if (c != ' ' && c != '\t' && c != '\r') {
            printf("n/a");
            return 0;
        }
    }

    int product = 1;
    int has_odd = 0;

    do {
        int digit = n % 10;
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