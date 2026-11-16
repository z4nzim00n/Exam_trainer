#include <stdio.h>

int main(void) {
    char s[102];

    if (fgets(s, 102, stdin) == NULL || s[0] == '\n') {
        printf("No");
        return 0;
    }

    for (int i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
        int sym = (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z');
        int numb = s[i] >= '0' && s[i] <= '9';
        int under = s[i] == '_';

        if (!sym && !under && !(numb && i > 0)) {
            printf("No");
            return 0;
        }
    }

    printf("Yes");
    return 0;
}