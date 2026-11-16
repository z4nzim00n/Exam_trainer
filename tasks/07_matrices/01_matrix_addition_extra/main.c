#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
        return 0;
    }
    int* arr = calloc((size_t)n * n, sizeof(*arr));
    for (int i = 0; i < n * n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            printf("n/a");
            return 0;
        }
    }

    for (int i = 0; i < n * n; i++) {
        int temp = 0;
        if (scanf("%d", &temp) != 1) {
            free(arr);
            printf("n/a");
            return 0;
        }

        arr[i] += temp;
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) printf("\n");
        for (int j = 0; j < n; j++) {
            if (j > 0) printf(" ");
            printf("%d", arr[i * n + j]);
        }
    }

    free(arr);
    return 0;
}