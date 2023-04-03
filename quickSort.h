#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "printVec.h"

template<typename Comparable>
void quickSortStableRec(vector<Comparable> &vec, int &reads, int &writes) {
    // Recursive base case
    if (vec.size() <= 1) {
        return;
    }

    // Choose a partition element
    Comparable partition = vec[0];
    reads++;
    writes++;

    vector<Comparable> smaller, equal, larger;
    // Loop through vec and populate smaller, equal, larger
    int i;
    for (i = 0; i < vec.size(); ++i) {
        if (vec[i] < partition) {
            smaller.push_back(vec[i]);
            reads++;
            writes++;
        } else if (vec[i] > partition) {
            reads += 2;
            larger.push_back(vec[i]);
            reads++;
            writes++;
        } else {
            reads += 2;
            equal.push_back(vec[i]);
            reads++;
            writes++;
        }
        reads += 2;
    }

    // Recursive calls
    quickSortStableRec(smaller, reads, writes);
    quickSortStableRec(larger, reads, writes);

    // Copy elements from smaller, equal, and larger back into vec
    for (i = 0; i < vec.size(); ++i) {
        if (i < smaller.size()) {
            vec[i] = smaller[i];
        } else if (i < smaller.size() + equal.size()) {
            vec[i] = equal[i - smaller.size()];
        } else {
            vec[i] = larger[i - smaller.size() - equal.size()];
        }
        reads++;
        writes++;
    }

    // printVec(vec);
}

template<typename Comparable>
void quickSortStable(vector<Comparable> vec, int &reads, int &writes) {
    quickSortStableRec(vec, reads, writes);
}

#endif
