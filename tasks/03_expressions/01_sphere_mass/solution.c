#include <math.h>
#include <stdio.h>

int main(void) {
    double radius;
    if (scanf("%lf", &radius) != 1 || radius < 0) {
        printf("n/a");
        return 0;
    }

    double V = (4.0 / 3.0) * M_PI * (radius * radius * radius);
    double m = 21500.0 * V;
    printf("%.0lf", round(m));

    return 0;
}
