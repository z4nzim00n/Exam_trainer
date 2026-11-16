#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("n/a");
        return 0;
    }

    int s;
    while ((s = getchar()) != '\n') {
        if (s != '\n' && s != '\0') {
            printf("n/a");
            return 0;
        }
    }

    int c = 1;
    for (int i = 0; i <= n; i++) {
        if (i > 0) printf(" ");
        printf("%d", c);
        c = c * (n - i) / (i + 1);
    }

    return 0;
}