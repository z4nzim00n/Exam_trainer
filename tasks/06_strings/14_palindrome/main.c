#include <stdio.h>

int main(void) {
    char s[102];
    int size = 0;
    if (fgets(s, 102, stdin) != NULL) {
        for (int i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] - 'A' + 'a';
            }

            size++;
        }
    }

    int l = 0;
    int r = size - 1;

    while (l <= r) {
        if (s[l] != s[r]) {
            printf("NO");
            return 0;
        }
        l++;
        r--;
    }

    printf("YES");
    return 0;
}