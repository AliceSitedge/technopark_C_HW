#include "gtest/gtest.h"

#include "matrix.h"

TEST(NULL, Test1) {
    int size = 2;
    ASSERT_EQ(size, 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
