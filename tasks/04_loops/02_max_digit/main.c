#include <stdio.h>

int main(void) {
    int n;
    int max = 0;
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

    do {
        int digit = n % 10;
        if (digit < 0) {
            digit = -digit;
        }
        if (digit > max) {
            max = digit;
        }
        n /= 10;
    } while (n != 0);

    printf("%d", max);
    return 0;
}