#include <stdio.h>

int main(void) {
    char text[102];
    int letters = 0;
    int digits = 0;

    if (fgets(text, sizeof(text), stdin) != NULL) {
        for (int i = 0; text[i] != '\0' && text[i] != '\n'; i++) {
            char ch = text[i];

            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                letters++;
            } else if (ch >= '0' && ch <= '9') {
                digits++;
            }
        }
    }

    printf("%d %d", letters, digits);
    return 0;
}