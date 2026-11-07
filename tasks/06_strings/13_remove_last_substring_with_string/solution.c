#include <stdio.h>
#include <string.h>

int main(void) {
    char str[1000] = {0};
    char sub[1000] = {0};

    if (fgets(str, sizeof str, stdin) == NULL) {
        return 0;
    }
    if (fgets(sub, sizeof sub, stdin) == NULL) {
        sub[0] = '\0';
    }

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