#include <stdio.h>

int main(void) {
    char path[256];

    if (scanf("%255s", path) != 1) {
        printf("n/a");
        return 0;
    }

    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("n/a");
        return 0;
    }

    long sum = 0;
    int count = 0;
    int number;
    int status;

    while ((status = fscanf(file, "%d", &number)) == 1) {
        sum += number;
        count++;
    }

    fclose(file);

    if (status != EOF || count == 0) {
        printf("n/a");
    } else {
        printf("%ld", sum);
    }

    return 0;
}