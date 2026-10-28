#include <stdio.h>

int main(void) {
    char c[102];
    int len = 0;

    if (fgets(c, sizeof(c), stdin) != NULL) {
        for (int i = 0; c[i] != '\0' && c[i] != '\n'; i++) {
            if (c[i] >= 'A' && c[i] <= 'Z') {
                c[i] = c[i] - 'A' + 'a';
            }
            len++;
        }
    }

    int l = 0;
    int r = len - 1;

    while (l < r) {
        if (c[l] != c[r]) {
            printf("NO");
            return 0;
        }
        l++;
        r--;
    }

    printf("YES");
    return 0;
}
