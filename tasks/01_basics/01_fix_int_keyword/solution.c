#include <stdio.h>

int main(void) {
    int a, b;

    if (scanf("%d %d", &a, &b) != 2) {
        printf("n/a");
        return 0;
    }

    printf("%d", a * b);
    return 0;
}