#include <stdio.h>

int main(void) {
    int value = 1;
    double pi = 3.141;

    if (scanf("%d", &value) != 1) {
        printf("n/a");
        return 0;
    }
    printf("%.2f", value * pi);

    return 0;
}
