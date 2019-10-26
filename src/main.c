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
    }

    shared_merge_sort(arr, size);

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("Error at line %d: %d is greater then %d\n", i, arr[i], arr[i+1]);
        }
    }

    FILE *output = fopen(argv[2], "w");
    for (int i = 0; i < size; i++) {
        fprintf(output, "%d\n", arr[i]);
    }

    fclose(input);
    fclose(output);
    free(arr);
    return 0;
}
