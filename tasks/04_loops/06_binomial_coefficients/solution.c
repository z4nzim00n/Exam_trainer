#include <stdio.h>

int main(void) {
    int n;
    int ch;

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("n/a");
        return 0;
    }

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch != ' ' && ch != '\t' && ch != '\r') {
            printf("n/a");
            return 0;
        }
    }

    unsigned long long c = 1;

    for (int k = 0; k <= n; k++) {
        if (k > 0) {
            printf(" ");
        }
        printf("%llu", c);
        c = c * (n - k) / (k + 1);
    }

    return 0;
}