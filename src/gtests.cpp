#include "gtest/gtest.h"

extern "C" {
#include "matrix.h"
}

TEST(Matrix, Rows_and_columns) {
    size_t rows = 2, cols = 2;
    Matrix *matrix = create_matrix(rows, cols);
    if (matrix == NULL) {
        return;
    }

    EXPECT_EQ(matrix->rows, rows);
    EXPECT_EQ(matrix->cols, cols);

    free_matrix(matrix);
}

TEST(Multiply, Different_values) {
    size_t rows = 2, cols = 2;
    Matrix *matrix = create_matrix(rows, cols);
    if (matrix == NULL) {
        return;
    }

    for (size_t i = 0; i < rows * cols; i++) {
        matrix->data[i] = int(i);
    }

    Matrix *new_matrix = multiply_elements(matrix);

    for (size_t i = 0; i < rows * cols; i++) {
        EXPECT_EQ(new_matrix->data[i], 0);
    }

    //free_matrix(matrix);
    free_matrix(new_matrix);
}

TEST(Multiply, Equal_values) {
    size_t rows = 2, cols = 2;
    Matrix *matrix = create_matrix(rows, cols);
    if (matrix == NULL) {
        return;
    }

    for (size_t i = 0; i < rows * cols; i++) {
        matrix->data[i] = int(1);
    }

    Matrix *new_matrix = multiply_elements(matrix);

    for (size_t i = 0; i < rows * cols; i++) {
        EXPECT_EQ(new_matrix->data[i], i);
    }

    free_matrix(matrix);
    free_matrix(new_matrix);
}

TEST(Multiply, Random_values) {
    size_t rows = 2, cols = 2;
    Matrix *matrix = create_matrix(rows, cols);
    if (matrix == NULL) {
        return;
    }

    matrix->data[0] = 1;
    matrix->data[1] = 2;
    matrix->data[2] = 2;
    matrix->data[3] = 1;

    Matrix *new_matrix = multiply_elements(matrix);

    EXPECT_EQ(new_matrix->data[0], 0);
    EXPECT_EQ(new_matrix->data[1], 0);
    EXPECT_EQ(new_matrix->data[2], 2);
    EXPECT_EQ(new_matrix->data[3], 1);

    free_matrix(matrix);
    free_matrix(new_matrix);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
