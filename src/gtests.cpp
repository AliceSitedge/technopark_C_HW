#include "gtest/gtest.h"
#include <fstream>

extern "C" {
#include "static_sort.h"
#include "shared_sort.h"
}

#define MAX_SIZE 100000

TEST(Sort, Test1) {
    std::ifstream fin("../tests/input/test1.txt");

    int *arr = new int[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        fin >> arr[i];
    }

    clock_t begin = 0, end = 0;
    begin = clock();
    static_merge_sort(arr, MAX_SIZE);
    end = clock();
    std::cout << "Sorting time: " << float(end - begin) / CLOCKS_PER_SEC << std::endl;

    std::ifstream fout("../tests/output/test1.txt");
    for (int i = 0; i < MAX_SIZE; i++) {
        int temp = 0;
        fout >> temp;
        EXPECT_EQ(arr[i], temp);
    }

    fin.close();
    fout.close();
    delete[] arr;
}

TEST(Sort, Test2) {
    std::ifstream fin("../tests/input/test2.txt");

    int *arr = new int[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        fin >> arr[i];
    }

    clock_t begin = 0, end = 0;
    begin = clock();
    static_merge_sort(arr, MAX_SIZE);
    end = clock();
    std::cout << "Sorting time: " << float(end - begin) / CLOCKS_PER_SEC << std::endl;

    std::ifstream fout("../tests/output/test2.txt");
    for (int i = 0; i < MAX_SIZE; i++) {
        int temp = 0;
        fout >> temp;
        EXPECT_EQ(arr[i], temp);
    }

    fin.close();
    fout.close();
    delete[] arr;
}

TEST(Sort, Test3) {
    std::ifstream fin("../tests/input/test3.txt");

    int *arr = new int[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        fin >> arr[i];
    }

    clock_t begin = 0, end = 0;
    begin = clock();
    static_merge_sort(arr, MAX_SIZE);
    end = clock();
    std::cout << "Sorting time: " << float(end - begin) / CLOCKS_PER_SEC << std::endl;

    std::ifstream fout("../tests/output/test3.txt");
    for (int i = 0; i < MAX_SIZE; i++) {
        int temp = 0;
        fout >> temp;
        EXPECT_EQ(arr[i], temp);
    }

    fin.close();
    fout.close();
    delete[] arr;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
