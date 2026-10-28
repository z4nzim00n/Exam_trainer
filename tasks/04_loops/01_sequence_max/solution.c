#include <stdio.h>

int main(void) {
    int x;
    int max = 0;

    while (scanf("%d", &x) == 1 && x != -1) {
        if (x > max) {
            max = x;
        }
    }

    printf("%d", max);
    return 0;
}
