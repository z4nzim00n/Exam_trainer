#include <stdio.h>

int main(void) {
    int x = 0;
    double pi = 3.141;

    if (scanf("%d", &x) != 1) {
        printf("n/a");
        return 0;
    }
    printf("%.2f", pi * x);

    return 0;
}
