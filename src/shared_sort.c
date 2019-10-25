#include <memory.h>
#include <malloc.h>
#include <pthread.h>

#include "shared_sort.h"

typedef struct Merge_args {
    int *first;
    int first_len;
    int *second;
    int second_len;
    int *dest;
} Merge_args;


typedef struct Merge_sort_args {
    int *arr;
    int n;
} Merge_sort_args;

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

void *thread_merge_sort(void *args) {
    int *arr = ((Merge_sort_args*)args)->arr;
    int n = ((Merge_sort_args*)args)->n;

    if (n == 1) {
        return NULL;
    }

    int first_len = n / 2;
    int second_len = n - first_len;

    pthread_t thread;
    Merge_sort_args *spawn_args = calloc(1, sizeof(Merge_sort_args));
    spawn_args->arr = arr;
    spawn_args->n = first_len;
    int errflag = pthread_create(&thread, NULL, thread_merge_sort, spawn_args);
    if (errflag != 0) {
        free(spawn_args);
        return NULL;
    }
    free(spawn_args);
    shared_merge_sort(arr + first_len, second_len);
    pthread_join(thread, NULL);


    int *temp = calloc((size_t)n, sizeof(int));
    merge(arr, first_len, arr + first_len, second_len, temp);

    memcpy(arr, temp, n * sizeof(int));
    free(temp);
}

void shared_merge_sort(int *arr, int n) {
    Merge_sort_args *args = calloc(1, sizeof(Merge_sort_args));
    args->arr = arr;
    args->n = n;
    thread_merge_sort(args);
    free(args);
}
