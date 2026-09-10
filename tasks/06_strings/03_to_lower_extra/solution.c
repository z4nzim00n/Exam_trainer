#include <stdio.h>

int main(void) {
    int ch;

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
        }
        putchar(ch);
    }

    return 0;
}