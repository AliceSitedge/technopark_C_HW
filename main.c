#include <stdio.h>
#include <malloc.h>

struct Pair {
    int x;
    int y;
};

typedef struct Pair Pair;

int *multiply_elements(const int *matrix, size_t rows, size_t cols) {
    if (matrix == NULL || rows == 0 || cols == 0) {
        return NULL;
    }

    int *new_matrix = calloc(rows * cols, sizeof(int));
    if (new_matrix == NULL) {
        return NULL;
    }

    Pair *entries = calloc(rows * cols, sizeof(Pair));
    if (entries == NULL) {
        free(new_matrix);
        return NULL;
    }

    int n = 0;
    for (size_t i = 0; i < rows * cols; i++) {
        int j = 0;
        while(entries[j].x != matrix[i] && j != n) {
            j++;
        }
        if (j == n) {
            entries[j].x = matrix[i];
            n++;
        }
        new_matrix[i] = entries[j].y;
        entries[j].y++;
    }

    return new_matrix;
}

int main() {
    size_t rows = 0, cols = 0;
    scanf("%zu%zu", &rows, &cols);
    int *matrix = calloc(rows * cols, sizeof(int));
    for (size_t i = 0; i < rows * cols; i++) {
        scanf("%d", &matrix[i]);
    }
    int *new_matrix = multiply_elements(matrix, (size_t)rows, (size_t)cols);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("%d ", new_matrix[i * cols + j]);
        }
        puts("");
    }

    return 0;
}