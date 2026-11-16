#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
        return 0;
    }

    int* a = malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("n/a");
            free(a);
            return 0;
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        if (scanf("%d", &temp) != 1) {
            printf("n/a");
            free(a);
            return 0;
        }
        result += a[i] * temp;
    }

    free(a);
    printf("%d", result);
    return 0;
}