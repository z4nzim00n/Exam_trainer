#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
        return 0;
    }

    int *a = malloc(n * sizeof(int));

    if (a == NULL) {
        printf("n/a");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            free(a);
            printf("n/a");
            return 0;
        }
    }

    long long sum = 0;
    int temp;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &temp) != 1) {
            free(a);
            printf("n/a");
            return 0;
        }

        sum += (long long)a[i] * temp;
    }

    free(a);

    printf("%lld", sum);

    return 0;
}