#include <stdio.h>

int main(void) {
    int value;
    int result = 0;

    while (scanf("%d", &value) == 1 && value != -1) {
        result ^= value;
    }

    printf("%d", result);
    return 0;
}