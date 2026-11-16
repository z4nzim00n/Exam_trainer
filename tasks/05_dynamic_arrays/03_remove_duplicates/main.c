#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int* a = NULL;
    int size = 0;

    while (scanf("%d", &n) == 1 && n != -1) {
        if (n < 0) {
            printf("n/a");
            free(a);
            return 0;
        }

        int found = 0;

        for (int i = 0; i < size; i++) {
            if (n == a[i]) {
                found = 1;
            }
        }

        if (!found) {
            int* temp = realloc(a, (size + 1) * sizeof(int));
            a = temp;
            a[size] = n;
            size++;
        }
    }

    if (n != -1) {
        free(a);
        printf("n/a");
        return 0;
    }

    for (int i = 0; i < size; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }

    free(a);
    return 0;
}