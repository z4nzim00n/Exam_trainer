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
        array[size] = value;
        size++;
    }

    if (value != -1 || size == 0) {
        free(array);
        printf("n/a");
        return 0;
    }

    int left = 0;
    int right = size - 1;
    int first = 1;

    while (left <= right) {
        if (!first) {
            printf(" ");
        }

        printf("%d", array[left]);
        first = 0;

        if (left != right) {
            printf(" %d", array[right]);
        }

        left++;
        right--;
    }

    free(array);

    return 0;
}