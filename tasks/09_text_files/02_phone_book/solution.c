#include <stdio.h>
#include <string.h>

int main(void) {
    char path[256];
    char line[256];

    if (scanf("%255s", path) != 1) {
        printf("n/a");
        return 0;
    }

    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("n/a");
        return 0;
    }

    const char* mask = "8-ddd-ddd-dd-dd";
    int count = 0;
    int ok = 1;

    while (ok && fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        const char* colon = strchr(line, ':');
        if (colon == NULL || colon == line || strlen(colon + 1) != 15) {
            ok = 0;
        } else {
            const char* phone = colon + 1;
            for (int i = 0; i < 15; i++) {
                if (mask[i] == 'd') {
                    if (phone[i] < '0' || phone[i] > '9') {
                        ok = 0;
                    }
                } else if (phone[i] != mask[i]) {
                    ok = 0;
                }
            }
        }
        count++;
    }

    if (!ok || count == 0) {
        printf("n/a");
        fclose(file);
        return 0;
    }

    rewind(file);
    count = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char* colon = strchr(line, ':');
        char* phone = colon + 1;
        *colon = '\0';

        if (count > 0) {
            printf("\n");
        }
        printf("%s +7(%.3s)%.3s-%.2s-%.2s", line, phone + 2, phone + 6, phone + 10, phone + 13);
        count++;
    }

    fclose(file);

    return 0;
}