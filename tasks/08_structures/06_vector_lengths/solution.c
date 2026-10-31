#include <math.h>
#include <stdio.h>

typedef struct {
    int x;
    int y;
    int z;
} Vector;

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        printf("n/a");
        return 0;
    }

    Vector vectors[n];

    for (int i = 0; i < n; i++) {
        if (scanf("%d %d %d", &vectors[i].x, &vectors[i].y, &vectors[i].z) != 3) {
            printf("n/a");
            return 0;
        }
    }

    double d;
    if (scanf("%lf", &d) != 1) {
        printf("n/a");
        return 0;
    }

    double sum = 0;

    for (int i = 0; i < n; i++) {
        double x = vectors[i].x;
        double y = vectors[i].y;
        double z = vectors[i].z;
        double length = sqrt(x * x + y * y + z * z);

        if (length > d) {
            sum += length;
        }
    }

    printf("%.0f", round(sum));

    return 0;
}