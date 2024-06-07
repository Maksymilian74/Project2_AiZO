#ifndef QUICKSORT_H
#define QUICKSORT_H

struct Edges {
    int from, to, weight;
};

class QuickSort {
public:
    static void sort(Edges* edgeArray, int low, int high);
private:
    static int partition(Edges* edgeArray, int low, int high);
};

#endif
