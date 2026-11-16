#include <math.h>
#include <stdio.h>

int main(void) {
    double n;
    if (scanf("%lf", &n) != 1) {
        printf("n/a");
        return 0;
    }

    printf("%.0lf", round(n * 57.29));
    return 0;
}