#include "num_counts.h"

int count_entries(NumCount *entries, size_t filled, int elem) {
    int j = 0;
    while (entries[j].num != elem && j < filled) {
        j++;
    }

    if (j == filled) {
        entries[j].num = elem;
    }

    return entries[j].count++;
}
