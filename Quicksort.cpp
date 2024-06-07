#include "QuickSort.h"
#include <iostream>
using  namespace std;

int QuickSort::partition(Edges* edgeArray, int low, int high) {
    int pivot = edgeArray[high].weight;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (edgeArray[j].weight < pivot) {
            i++;
            swap(edgeArray[i], edgeArray[j]);
        }
    }
    swap(edgeArray[i + 1], edgeArray[high]);
    return (i + 1);
}

void QuickSort::sort(Edges* edgeArray, int low, int high) {
    if (low < high) {
        int pi = partition(edgeArray, low, high);
        sort(edgeArray, low, pi - 1);
        sort(edgeArray, pi + 1, high);
    }
}

