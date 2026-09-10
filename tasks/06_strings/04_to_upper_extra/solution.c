#include <stdio.h>

int main(void) {
    int ch;

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - 'a' + 'A';
        }
        putchar(ch);
    }

    return 0;
}