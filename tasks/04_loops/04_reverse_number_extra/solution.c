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

/*
#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("n/a");
        return 0;
    }

    while (n != 0 && n % 10 == 0) {
        n = n / 10;
    }

    if (n == 0) {
        printf("0");
        return 0;
    }

    while (n != 0) {
        printf("%d", n % 10);
        n = n / 10;
    }

    return 0;
}
*/
