#include <stdio.h>

int main(void) {
    int left = 2, right = 1;

    if (scanf("%d %d", &left, &right) != 2) {
        printf("n/a");
        return 0;
    }
    printf("%d", left * right);

    return 0;
}
