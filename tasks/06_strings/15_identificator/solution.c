#include <stdio.h>

int main(void) {
    char s[102];
    int n = 0;
    int ch;

    int is_identifier = 0;

    while ((ch = getchar()) != EOF && ch != '\n') {
        s[n++] = ch;
        is_identifier = 1;
    }

    for (int i = 0; i < n; i++) {
        int letter = (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z');
        int digit = s[i] >= '0' && s[i] <= '9';

        if (!(letter || s[i] == '_' || (digit && i > 0))) {
            is_identifier = 0;
            break;
        }
    }

    printf("%s", is_identifier ? "Yes" : "No");
    return 0;
}