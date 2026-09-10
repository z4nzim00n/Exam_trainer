#include <stdio.h>

int main(void) {
    char text[102];
    int length = 0;
    int palindrome = 1;

    if (fgets(text, sizeof(text), stdin) != NULL) {
        while (text[length] != '\0' && text[length] != '\n') {
            length++;
        }
    }

    for (int i = 0; i < length / 2; i++) {
        if (text[i] != text[length - 1 - i]) {
            palindrome = 0;
            break;
        }
    }

    printf("%d", palindrome);
    return 0;
}