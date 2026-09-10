#include <math.h>
#include <stdio.h>

int main(void) {
    double radians;
    if (scanf("%lf", &radians) != 1) {
        printf("n/a");
        return 0;
    }

    double result = radians * 57.29;
    printf("%.0lf", round(result));

    return 0;
}