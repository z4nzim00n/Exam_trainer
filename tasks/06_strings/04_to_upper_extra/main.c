#include <stdio.h>

int main(void) {
    int a, b, c;

    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("n/a");
        return 0;
    }

    printf("%d", (a < c && c < b) || (b < c && c < a));

    return 0;
}
