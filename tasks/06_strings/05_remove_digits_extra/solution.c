#include <stdio.h>

int main(void) {
    int ch;

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch < '0' || ch > '9') {
            putchar(ch);
        }
    }

    return 0;
}