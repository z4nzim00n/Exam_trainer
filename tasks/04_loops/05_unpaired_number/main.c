#include <stdio.h>

int main(void) {
    int n;
    int result = 0;

    while (scanf("%d", &n) == 1 && n != -1) {
        result = result ^ n;
    }

    printf("%d", result);
    return 0;
}