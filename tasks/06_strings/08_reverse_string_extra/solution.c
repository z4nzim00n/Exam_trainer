#include <stdio.h>

int main(void) {
    char str[102];
    int len = 0;
    int ch;

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (len < 101) {
            str[len] = (char)ch;
            len++;
        }
    }
    str[len] = '\0';

    for (int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }

    return 0;
}