#include <memory.h>
#include <malloc.h>

#include "static_sort.h"

void merge(int *first, int first_len, int *second, int second_len, int *dest) {
    int ptr1 = 0;
    int ptr2 = 0;
    int i = 0;

    while (ptr1 != first_len && ptr2 != second_len) {
        if (first[ptr1] < second[ptr2]) {
            dest[i++] = first[ptr1++];
        } else {
            dest[i++] = second[ptr2++];
        }
    }

    if (ptr1 == first_len) {
        memcpy(dest + i, second + ptr2, (second_len - ptr2) * sizeof(int));
    } else {
        memcpy(dest + i, first + ptr1, (first_len - ptr1) * sizeof(int));
    }
}

void static_merge_sort(int *arr, int n) {
    if (n == 1) {
        return;
    }

    int first_len = n / 2;
    int second_len = n - first_len;
    static_merge_sort(arr, first_len);
    static_merge_sort(arr + first_len, second_len);

    int *temp = calloc((size_t)n, sizeof(int));
    merge(arr, first_len, arr + first_len, second_len, temp);

    memcpy(arr, temp, n * sizeof(int));
    free(temp);
}
