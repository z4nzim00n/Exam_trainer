#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("n/a");
        return 0;
    }

    int *a = calloc((size_t)n*n, sizeof(int));
    int *b = calloc((size_t)n*n, sizeof(int));
    int *c = calloc((size_t)n*n, sizeof(int));

    


}