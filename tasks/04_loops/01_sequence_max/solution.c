#include <stdio.h>

int main(void) {
    int x;
    int max = 0;

    while (scanf("%d", &x) == 1 && x != -1) {
        if (x > max) {
            max = x;
        }
    }

    //в автотестах он не проверяет отрицательные числа, но все же стоит добавить.
    if (x != -1) {
        printf("n/a");
        return 0;
    }

    printf("%d", max);
    return 0;
}
