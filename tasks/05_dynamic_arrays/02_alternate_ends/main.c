#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int* a = NULL;
    int size = 0;

    while (scanf("%d", &n) == 1 && n != -1) {
        if (n < -1) {
            printf("n/a");
            free(a);
            return 0;
        }

        int* temp = realloc(a, (size + 1) * sizeof(int));
        if (temp == NULL) {
            free(temp);
            return 0;
        }
        a = temp;
        a[size] = n;
        size++;
    }

    if (n != -1 || size == 0) {
        printf("n/a");
        free(a);
        return 0;
    }

    int l = 0;
    int r = size - 1;
    int first = 0;

    printf("%d", a[l]);
    l++;

    while (l <= r) {
        if (first == 0) {
            printf(" %d", a[r]);
            r--;
            first = 1;
        } else {
            printf(" %d", a[l]);
            l++;
            first = 0;
        }
    }

    free(a);
    return 0;
}