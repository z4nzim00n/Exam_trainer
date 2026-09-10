#include <stdio.h>

int main(void) {
    int x1, x2;

    if (scanf("%d %d", &x1, &x2) != 2) {
        printf("n/a");
        return 0;
    }
    printf("%d", x1 * x2);

    return 0;
}
