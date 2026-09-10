#include <stdio.h>

int main(void) {
    int shift;
    int ch;

    if (scanf("%d", &shift) != 1) {
        return 0;
    }
    getchar();

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + shift) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + shift) % 26;
        }
        putchar(ch);
    }

    return 0;
}