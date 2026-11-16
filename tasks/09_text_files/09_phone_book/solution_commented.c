/*
 * EXAM_09_09. Телефонный справочник.
 *
 * Проход 1 — проверяем все строки, ничего не печатая.
 * Проход 2 — печатаем. Так при ошибке в любой строке вывод — только "n/a".
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char path[256];
    char line[256];
    /* 'd' — цифра, остальные символы должны совпасть */
    const char* mask = "8-ddd-ddd-dd-dd";
    int count = 0;
    int ok = 1;

    /* путь к файлу */
    if (scanf("%255s", path) != 1) {
        printf("n/a");
        return 0;
    }

    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("n/a");
        return 0;
    }

    /* ПРОХОД 1: проверка. Как только нашли ошибку, ok = 0 и цикл останавливается. */
    while (ok && fgets(line, sizeof(line), file) != NULL) {
        /* убираем перевод строки */
        line[strcspn(line, "\n")] = '\0';

        char* colon = strchr(line, ':');
        /* двоеточие есть, имя не пустое, телефон ровно 15 символов */
        if (colon == NULL || colon == line || strlen(colon + 1) != 15) {
            ok = 0;
        } else {
            char* phone = colon + 1;
            for (int i = 0; i < 15 && ok; i++) {
                if (mask[i] == 'd') {
                    if (phone[i] < '0' || phone[i] > '9') ok = 0;
                } else if (phone[i] != mask[i]) {
                    ok = 0;
                }
            }
        }
        count++;
    }

    /* ошибка в данных или пустой файл */
    if (!ok || count == 0) {
        printf("n/a");
        fclose(file);
        return 0;
    }

    /* ПРОХОД 2: файл корректен, печатаем контакты. */
    rewind(file);
    count = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        char* colon = strchr(line, ':');
        char* phone = colon + 1;
        /* теперь line — только имя; '\n' в конце телефона нам не мешает, мы его не печатаем */
        *colon = '\0';

        /* '\n' перед каждой строкой, кроме первой: в конце вывода переноса нет */
        if (count > 0) printf("\n");

        /* 8-950-111-22-33 → +7(950)111-22-33: берём части с нужных позиций */
        printf("%s +7(%.3s)%.3s-%.2s-%.2s", line, phone + 2, phone + 6, phone + 10, phone + 13);
        count++;
    }

    fclose(file);
    return 0;
}
