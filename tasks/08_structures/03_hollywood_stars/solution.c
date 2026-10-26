#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    char surname[100];
    int height;
} Person;

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        printf("n/a");
        return 0;
    }

    Person people[n];

    for (int i = 0; i < n; i++) {
        if (scanf("%99s %99s %d", people[i].name, people[i].surname, &people[i].height) != 3) {
            printf("n/a");
            return 0;
        }
    }

    char search[100];
    if (scanf("%99s", search) != 1) {
        printf("n/a");
        return 0;
    }

    int count = 0;
    long sum = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(search, people[i].name) == 0) {
            count++;
            sum += people[i].height;
        }
    }

    int first = 1;

    for (int i = 0; i < n; i++) {
        if (strcmp(search, people[i].name) == 0) {
            if (!first) {
                printf(", ");
            }
            printf("%s", people[i].surname);
            first = 0;
        }
    }

    if (count > 0) {
        printf(": %.0f", round((double)sum / count));
    } else {
        printf("n/a");
    }

    return 0;
}