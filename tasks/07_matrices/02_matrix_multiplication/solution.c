#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
        return 0;
    }

    int *a = malloc((size_t)n * n * sizeof(int));
    int *b = malloc((size_t)n * n * sizeof(int));
    int *c = malloc((size_t)n * n * sizeof(int));

    if (a == NULL || b == NULL || c == NULL) {
        free(a);
        free(b);
        free(c);
        printf("n/a");
        return 0;
    }

    for (int i = 0; i < n * n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            free(a);
            free(b);
            free(c);
            printf("n/a");
            return 0;
        }
    }

    for (int i = 0; i < n * n; i++) {
        if (scanf("%d", &b[i]) != 1) {
            free(a);
            free(b);
            free(c);
            printf("n/a");
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i * n + j] = 0;
            for (int k = 0; k < n; k++) {
                c[i * n + j] += a[i * n + k] * b[k * n + j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", c[i * n + j]);
        }
        if (i < n - 1) {
            printf("\n");
        }
    }

    free(a);
    free(b);
    free(c);

    return 0;
}