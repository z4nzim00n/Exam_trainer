#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("n/a");
        return 0;
    }

    if (n < 0) {
        n = -n;
    }

    int c;
    while ((c = getchar()) != '\n') {
        if (c != '\n' && c != '\0') {
            printf("n/a");
            return 0;
        }
    }

    int result = 1;
    int hasOdd = 0;

    while (n != 0) {
        if ((n % 10) % 2 != 0) {
            result *= n % 10;
            hasOdd = 1;
        }
        n = n / 10;
    }

    if (hasOdd) {
        printf("%d", result);
    } else {
        printf("0");
    }

    return 0;
}