#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "static_sort.h"
#include "shared_sort.h"

#define MAX_SIZE 100000

int main(int argc, char *argv[]) {

    FILE *input = fopen(argv[1], "r");
    assert(input != NULL);

    int size = 0;
    fscanf(input, "%d", &size);
    assert(size > 0);

    int *arr = calloc((size_t)size, sizeof(int));
    assert(arr != NULL);

    for (int i = 0; i < size; i++) {
        fscanf(input, "%d", &arr[i]);
//        printf("%d ", arr[i]);
    }

    shared_merge_sort(arr, size);

    FILE *output = fopen(argv[2], "w");
    for (int i = 0; i < size; i++) {
        fprintf(output, "%d\n", arr[i]);
    }


//    srand(time(NULL));
//
//    FILE *input = fopen(argv[1], "r");
//
//    int *arr = calloc(MAX_SIZE, sizeof(int));
//    assert(arr != NULL);
//    for (int i = 0; i < MAX_SIZE; i++) {
//        fscanf(input, "%d", &arr[i]);
////        arr[i] = rand() % 100;
////        fprintf(input, "%d\n", arr[i]);
//    }
//
//    static_merge_sort(arr, MAX_SIZE);
//
//    FILE *output = fopen(argv[2], "w");
//    for (int i = 0; i < MAX_SIZE; i++) {
//        fprintf(output, "%d\n", arr[i]);
//    }

    fclose(input);
    fclose(output);
    free(arr);
    return 0;
}
