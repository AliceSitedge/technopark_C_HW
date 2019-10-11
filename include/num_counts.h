#ifndef INCLUDE_NUM_COUNTS_H_
#define INCLUDE_NUM_COUNTS_H_

#include <stdio.h>

struct NumCount {
    int num;
    int count;
};
typedef struct NumCount NumCount;

int count_entries(NumCount *entries, size_t filled, int elem);

#endif  // INCLUDE_NUM_COUNTS_H_
