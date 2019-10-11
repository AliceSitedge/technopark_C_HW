#ifndef INCLUDE_MATRIX_H_
#define INCLUDE_MATRIX_H_

#include <stdio.h>

struct Matrix {
    int *data;
    size_t rows;
    size_t cols;
};
typedef struct Matrix Matrix;

Matrix *create_matrix(size_t rows, size_t cols);
void fill_matrix(Matrix *matrix);
void free_matrix(Matrix *matrix);
int print_matrix(const Matrix *matrix);
Matrix *multiply_elements(const Matrix *matrix);

#endif  // INCLUDE_MATRIX_H_
