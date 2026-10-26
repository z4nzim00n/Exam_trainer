/*
 * EXAM_05_05. Перестановка наибольшего и наименьшего.
 *
 * Читаем числа до -1 в динамический массив, находим первые вхождения
 * минимума и максимума, меняем их местами и печатаем.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* array = NULL; /* пока пустой: realloc(NULL, ...) работает как malloc */
    int size = 0;      /* сколько чисел записано */
    int value = 0;

    /*
     * Читаем, пока читаются числа и это не -1.
     * Если scanf не смог прочитать число, цикл кончается, а value остаётся прежним (не -1).
     */
    while (scanf("%d", &value) == 1 && value != -1) {
        /* Увеличиваем массив на один элемент. Старые числа realloc сохраняет. */
        int* temp = realloc(array, (size + 1) * sizeof(int));

        /* Если памяти не хватило, старый array ещё жив: освобождаем его. */
        if (temp == NULL) {
            free(array);
            printf("n/a");
            return 0;
        }

        array = temp;
        array[size] = value;
        size++;
    }

    /*
     * Нормальный конец цикла: value == -1. Если это не так, то ввод оборвался
     * или встретилось не число. size == 0 — последовательность пустая.
     */
    if (value != -1 || size == 0) {
        free(array);
        printf("n/a");
        return 0;
    }

    int min = 0; /* индекс наименьшего */
    int max = 0; /* индекс наибольшего */

    /* Строгие < и > оставляют ПЕРВОЕ вхождение при равных значениях. */
    for (int i = 1; i < size; i++) {
        if (array[i] < array[min]) {
            min = i;
        }
        if (array[i] > array[max]) {
            max = i;
        }
    }

    /* Обмен через временную переменную. Если все числа равны, min == max, и ничего не меняется. */
    int swap = array[min];
    array[min] = array[max];
    array[max] = swap;

    for (int i = 0; i < size; i++) {
        /* Пробел ПЕРЕД числом, кроме первого: в конце лишнего пробела не будет. */
        if (i > 0) {
            printf(" ");
        }
        printf("%d", array[i]);
    }

    free(array);

    return 0;
}