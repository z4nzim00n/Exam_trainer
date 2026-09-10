#include <stdio.h>

int main(void) {
    int first = 3, second = 4;

    if (scanf("%d %d", &first, &second) != 2) {
        printf("n/a");
        return 0;
    }
    printf("%d", first * second);

    return 0;
}
