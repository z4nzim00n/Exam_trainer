#include <stdio.h>

int main(void) {
    int number;
    int reversed = 0;

    if (scanf("%d", &number) != 1) {
        return 0;
    }

    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }

    printf("%d", reversed);
    return 0;
}