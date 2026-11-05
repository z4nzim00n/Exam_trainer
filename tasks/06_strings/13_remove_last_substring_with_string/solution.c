#include <stdio.h>
#include <string.h>

int main() {
    char str[1000], sub[1000];

    fgets(str, sizeof str, stdin);
    fgets(sub, sizeof sub, stdin);
    str[strcspn(str, "\n")] = '\0';
    sub[strcspn(sub, "\n")] = '\0';

    int len = strlen(sub);
    char *last = NULL, *p = str;

    if (len > 0) {
        while ((p = strstr(p, sub)) != NULL) {
            last = p;
            p++;
        }
    }

    if (last != NULL) memmove(last, last + len, strlen(last + len) + 1);

    printf("%s", str);
    return 0;
}