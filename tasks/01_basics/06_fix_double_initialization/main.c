#include <stdio.h>

int main(void)
{
    int value = 1;
    double pi = "3.141";

    scanf("%d", &value);
    printf("%.2f", value * pi);

    return 0;
}