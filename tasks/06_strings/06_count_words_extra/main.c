#include <stdio.h>

int main(void) {
    char s[102];
    int len = 0;
    int wordCount = 0;
    int inWord = 0;

    if (fgets(s, 102, stdin) != NULL) {
        for (int i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
            if (inWord && s[i] == ' ') {
                inWord = 0;
            }

            if (s[i] != ' ' && s[i] != '\0' && s[i] != '\n' && inWord == 0) {
                wordCount++;
                inWord = 1;
            }

            len++;
        }
    }

    printf("%d", wordCount);
    return 0;
}