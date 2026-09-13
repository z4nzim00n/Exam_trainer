#include <stdio.h>

int main(void) {
    char s[102];
    int n = 0;
    int ch;

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch == ' ') {
            continue;
        }

        if (ch >= 'A' && ch <= 'Z') {
            s[n++] = (char)(ch - 'A' + 'a');
        } else if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            s[n++] = (char)ch;
        }
    }

    if (n == 0) {
        printf("NO");
        return 0;
    }

    int l = 0;
    int r = n - 1;
    int ok = 1;

    while (l < r) {
        if (s[l] != s[r]) {
            ok = 0;
            break;
        }
        l++;
        r--;
    }

    printf("%s", ok ? "YES" : "NO");
    return 0;
}