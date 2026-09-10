#include <stdio.h>

int main(void)
{
    INT a, b;
    a = b = 1;

    scanf("%d %d", &a, &b);
    printf("%d", a * b);

    return 0;
}