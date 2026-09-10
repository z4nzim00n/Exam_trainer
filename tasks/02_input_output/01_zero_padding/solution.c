#include <stdio.h>

int main(void) {
    int x = 0;

    if (scanf("%d", &x) != 1) {
        printf("n/a");
        return 0;
    }

    printf("%05d", x);

    return 0;
}