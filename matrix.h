#ifndef TECHNOPARK_C_HW1_MATRIX_H
#define TECHNOPARK_C_HW1_MATRIX_H

#include <stdio.h>

struct Matrix;
typedef struct Matrix Matrix;

Matrix *create_matrix(size_t rows, size_t cols);
void fill_matrix(Matrix *matrix);
void free_matrix(Matrix *matrix);
int print_matrix(const Matrix *matrix);
Matrix *multiply_elements(const Matrix *matrix);

#endif  // TECHNOPARK_C_HW1_MATRIX_H