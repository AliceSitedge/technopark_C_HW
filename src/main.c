#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "matrix.h"

int main() {
    int rows = 0, cols = 0;
    scanf("%d%d", &rows, &cols);
    assert(rows > 0 && cols > 0);

    Matrix *matrix = create_matrix((size_t)rows, (size_t)cols);
    fill_matrix(matrix);

    Matrix *new_matrix = multiply_elements(matrix);
    print_matrix(new_matrix);

    free_matrix(matrix);
    free_matrix(new_matrix);
    return 0;
}
