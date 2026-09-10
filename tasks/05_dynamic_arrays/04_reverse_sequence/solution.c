#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *array = NULL;
    int size = 0;
    int value = 0;

    while (scanf("%d", &value) == 1 && value != -1) {
        if (value < 0) {
            free(array);
            printf("n/a");
            return 0;
        }

        int *temp = realloc(array, (size + 1) * sizeof(int));

        if (temp == NULL) {
            free(array);
            printf("n/a");
            return 0;
        }

        array = temp;
        array[size++] = value;
    }

    if (value != -1) {
        free(array);
        printf("n/a");
        return 0;
    }

    for (int i = size - 1; i >= 0; i--) {
        if (i < size - 1) {
            printf(" ");
        }

        printf("%d", array[i]);
    }

    free(array);

    return 0;
}