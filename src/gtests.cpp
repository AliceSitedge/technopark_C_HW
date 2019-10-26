#include "gtest/gtest.h"
#include <fstream>
#include <sys/time.h>

extern "C" {
#include "static_sort.h"
#include "shared_sort.h"
}

#define MAX_SIZE 100000

TEST(Sort, Test1) {
    std::ifstream fin("./tests/input/test1.txt");
    if (!fin.is_open()) {
        FAIL() << "Couldn't open input file";
    }

    int arr1[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        fin >> arr1[i];
    }

    int arr2[MAX_SIZE];
    memcpy(arr2, arr1, MAX_SIZE * sizeof(int));

    struct timeval tv;

    gettimeofday(&tv, nullptr);
    double begin = tv.tv_sec + tv.tv_usec / 1.0e6;

    static_merge_sort(arr1, MAX_SIZE);

    gettimeofday(&tv, nullptr);
    double end = tv.tv_sec + tv.tv_usec / 1.0e6;

    std::cout << "Test1\n";
    std::cout << "Static merge sort: " << end - begin << " sec\n";

    gettimeofday(&tv, nullptr);
    begin = tv.tv_sec + tv.tv_usec / 1.0e6;

    shared_merge_sort(arr2, MAX_SIZE);

    gettimeofday(&tv, nullptr);
    end = tv.tv_sec + tv.tv_usec / 1.0e6;

    std::cout << "Shared merge sort: " << end - begin << " sec\n";

    std::ifstream fout("./tests/output/test1.txt");
    if (!fout.is_open()) {
        FAIL() << "Couldn't open output file";
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        int temp = 0;
        fout >> temp;
        EXPECT_EQ(arr1[i], temp);
        EXPECT_EQ(arr2[i], temp);
    }
}

TEST(Sort, Test2) {
    std::ifstream fin("./tests/input/test2.txt");
    if (!fin.is_open()) {
        FAIL() << "Couldn't open input file";
    }

    int arr1[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        fin >> arr1[i];
    }

    int arr2[MAX_SIZE];
    memcpy(arr2, arr1, MAX_SIZE * sizeof(int));

    struct timeval tv;

    gettimeofday(&tv, nullptr);
    double begin = tv.tv_sec + tv.tv_usec / 1.0e6;

    static_merge_sort(arr1, MAX_SIZE);

    gettimeofday(&tv, nullptr);
    double end = tv.tv_sec + tv.tv_usec / 1.0e6;

    std::cout << "Test2\n";
    std::cout << "Static merge sort: " << end - begin << " sec\n";

    gettimeofday(&tv, nullptr);
    begin = tv.tv_sec + tv.tv_usec / 1.0e6;

    shared_merge_sort(arr2, MAX_SIZE);

    gettimeofday(&tv, nullptr);
    end = tv.tv_sec + tv.tv_usec / 1.0e6;

    std::cout << "Shared merge sort: " << end - begin << " sec\n";

    std::ifstream fout("./tests/output/test2.txt");
    if (!fout.is_open()) {
        FAIL() << "Couldn't open output file";
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        int temp = 0;
        fout >> temp;
        EXPECT_EQ(arr1[i], temp);
        EXPECT_EQ(arr2[i], temp);
    }
}

TEST(Sort, Test3) {
    std::ifstream fin("./tests/input/test3.txt");
    if (!fin.is_open()) {
        FAIL() << "Couldn't open input file";
    }

    int arr1[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        fin >> arr1[i];
    }

    int arr2[MAX_SIZE];
    memcpy(arr2, arr1, MAX_SIZE * sizeof(int));

    struct timeval tv;

    gettimeofday(&tv, nullptr);
    double begin = tv.tv_sec + tv.tv_usec / 1.0e6;

    static_merge_sort(arr1, MAX_SIZE);

    gettimeofday(&tv, nullptr);
    double end = tv.tv_sec + tv.tv_usec / 1.0e6;

    std::cout << "Test3\n";
    std::cout << "Static merge sort: " << end - begin << " sec\n";

    gettimeofday(&tv, nullptr);
    begin = tv.tv_sec + tv.tv_usec / 1.0e6;

    shared_merge_sort(arr2, MAX_SIZE);

    gettimeofday(&tv, nullptr);
    end = tv.tv_sec + tv.tv_usec / 1.0e6;

    std::cout << "Shared merge sort: " << end - begin << " sec\n";

    std::ifstream fout("./tests/output/test3.txt");
    if (!fout.is_open()) {
        FAIL() << "Couldn't open output file";
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        int temp = 0;
        fout >> temp;
        EXPECT_EQ(arr1[i], temp);
        EXPECT_EQ(arr2[i], temp);
    }
}

TEST(Sort, Test4) {
    std::ifstream fin("./tests/input/test4.txt");
    if (!fin.is_open()) {
        FAIL() << "Couldn't open input file";
    }

    int arr1[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        fin >> arr1[i];
    }

    int arr2[MAX_SIZE];
    memcpy(arr2, arr1, MAX_SIZE * sizeof(int));

    struct timeval tv;

    gettimeofday(&tv, nullptr);
    double begin = tv.tv_sec + tv.tv_usec / 1.0e6;

    static_merge_sort(arr1, MAX_SIZE);

    gettimeofday(&tv, nullptr);
    double end = tv.tv_sec + tv.tv_usec / 1.0e6;

    std::cout << "Test4\n";
    std::cout << "Static merge sort: " << end - begin << " sec\n";

    gettimeofday(&tv, nullptr);
    begin = tv.tv_sec + tv.tv_usec / 1.0e6;

    shared_merge_sort(arr2, MAX_SIZE);

    gettimeofday(&tv, nullptr);
    end = tv.tv_sec + tv.tv_usec / 1.0e6;

    std::cout << "Shared merge sort: " << end - begin << " sec\n";

    std::ifstream fout("./tests/output/test4.txt");
    if (!fout.is_open()) {
        FAIL() << "Couldn't open output file";
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        int temp = 0;
        fout >> temp;
        EXPECT_EQ(arr1[i], temp);
        EXPECT_EQ(arr2[i], temp);
    }
}

TEST(Sort, Test5) {
    std::ifstream fin("./tests/input/test5.txt");
    if (!fin.is_open()) {
        FAIL() << "Couldn't open input file";
    }

    int arr1[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        fin >> arr1[i];
    }

    int arr2[MAX_SIZE];
    memcpy(arr2, arr1, MAX_SIZE * sizeof(int));

    struct timeval tv;

    gettimeofday(&tv, nullptr);
    double begin = tv.tv_sec + tv.tv_usec / 1.0e6;

    static_merge_sort(arr1, MAX_SIZE);

    gettimeofday(&tv, nullptr);
    double end = tv.tv_sec + tv.tv_usec / 1.0e6;

    std::cout << "Test5\n";
    std::cout << "Static merge sort: " << end - begin << " sec\n";

    gettimeofday(&tv, nullptr);
    begin = tv.tv_sec + tv.tv_usec / 1.0e6;

    shared_merge_sort(arr2, MAX_SIZE);

    gettimeofday(&tv, nullptr);
    end = tv.tv_sec + tv.tv_usec / 1.0e6;

    std::cout << "Shared merge sort: " << end - begin << " sec\n";

    std::ifstream fout("./tests/output/test5.txt");
    if (!fout.is_open()) {
        FAIL() << "Couldn't open output file";
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        int temp = 0;
        fout >> temp;
        EXPECT_EQ(arr1[i], temp);
        EXPECT_EQ(arr2[i], temp);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
