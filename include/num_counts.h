#ifndef TECHNOPARK_C_HW1_NUM_COUNTS_H
#define TECHNOPARK_C_HW1_NUM_COUNTS_H

#include <stdio.h>

struct NumCount {
    int num;
    int count;
};
typedef struct NumCount NumCount;

int count_entries(NumCount *entries, size_t filled, int elem);

#endif  // TECHNOPARK_C_HW1_NUM_COUNTS_H