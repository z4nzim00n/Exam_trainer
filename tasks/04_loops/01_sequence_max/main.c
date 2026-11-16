#include <stdio.h>

int main(void) {
    int n;
    int max = 0;

    while (scanf("%d", &n) == 1 && n != -1) {
        if (n < 0) {
            printf("n/a");
            return 0;
        }
        if (n > max) {
            max = n;
        }
    }

    if (n != -1) {
        printf("n/a");
        return 0;
    }

    printf("%d", max);
    return 0;
}