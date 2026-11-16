#include <math.h>
#include <stdio.h>

int main(void) {
    double n;
    if (scanf("%lf", &n) != 1 || n < 0) {
        printf("n/a");
        return 0;
    }

    double V = (4.0 / 3.0) * M_PI * (n * n * n);
    double m = 21500 * V;

    printf("%.0lf", round(m));
    return 0;
}