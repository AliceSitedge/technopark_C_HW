#include <malloc.h>

#include "matrix.h"
#include "num_counts.h"

struct Matrix {
    int *data;
    size_t rows;
    size_t cols;
};

Matrix *create_matrix(size_t rows, size_t cols) {
    Matrix *matrix = calloc(1, sizeof(Matrix));
    if (matrix == NULL) {
        return NULL;
    }

    matrix->data = calloc(rows * cols, sizeof(int));
    if (matrix->data == NULL) {
        free(matrix);
        return NULL;
    }

    matrix->rows = rows;
    matrix->cols = cols;

    return matrix;
}

void fill_matrix(Matrix *matrix) {
    for (size_t i = 0; i < matrix->rows * matrix->cols; i++) {
        scanf("%d", &matrix->data[i]);
    }
}

void free_matrix(Matrix *matrix) {
    if (matrix != NULL) {
        free(matrix->data);
    }
    free(matrix);
}

int print_matrix(const Matrix *matrix) {
    if (matrix == NULL) {
        return -1;
    }

    for (size_t i = 0; i < matrix->rows; i++) {
        for (size_t j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }

    return 0;
}

Matrix *multiply_elements(const Matrix *matrix) {
    if (matrix == NULL || matrix->rows == 0 || matrix->cols == 0) {
        return NULL;
    }

    Matrix *new_matrix = create_matrix(matrix->rows, matrix->cols);
    if (new_matrix == NULL) {
        return NULL;
    }

    NumCount *entries = calloc(matrix->rows * matrix->cols, sizeof(NumCount));
    if (entries == NULL) {
        free(new_matrix);
        return NULL;
    }

    size_t filled = 0;
    for (size_t i = 0; i < matrix->rows * matrix->cols; i++) {
        int count = count_entries(entries, filled, matrix->data[i]);
        new_matrix->data[i] = matrix->data[i] * count;
        if (count == 0) {
            filled++;
        }
    }

    free(entries);
    return new_matrix;
}
