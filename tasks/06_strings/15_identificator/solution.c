#include <stdio.h>

int main(void) {
    char s[102];
    int n = 0;
    int ch;

    while ((ch = getchar()) != EOF && ch != '\n') {
        s[n++] = (char)ch;
    }

    int ok = n > 0;

    for (int i = 0; i < n; i++) {
        int letter = (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z');
        int digit = s[i] >= '0' && s[i] <= '9';

        if (!(letter || s[i] == '_' || (digit && i > 0))) {
            ok = 0;
            break;
        }
    }

    printf("%s", ok ? "Yes" : "No");
    return 0;
}