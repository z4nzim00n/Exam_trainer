#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* array = NULL;
    int size = 0;
    int value = 0;

    while (scanf("%d", &value) == 1 && value != -1) {
        int* temp = realloc(array, (size + 1) * sizeof(int));

        if (temp == NULL) {
            free(array);
            printf("n/a");
            return 0;
        }

        array = temp;
        array[size] = value;
        size++;
    }

    if (value != -1 || size == 0) {
        free(array);
        printf("n/a");
        return 0;
    }

    int min = 0;
    int max = 0;

    for (int i = 1; i < size; i++) {
        if (array[i] < array[min]) {
            min = i;
        }
        if (array[i] > array[max]) {
            max = i;
        }
    }

    int swap = array[min];
    array[min] = array[max];
    array[max] = swap;

    for (int i = 0; i < size; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", array[i]);
    }

    free(array);

    return 0;
}