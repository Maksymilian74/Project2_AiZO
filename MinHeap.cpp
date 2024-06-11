#include "MinHeap.h"
#include <iostream>
#include <climits>

using namespace std;

MinHeap::MinHeap(int capacity) : capacity(capacity), heapSize(0) {
    heapArray = new int*[capacity];
    for (int i = 0; i < capacity; ++i) {
        heapArray[i] = new int[3];
    }
}

MinHeap::~MinHeap() {
    for (int i = 0; i < heapSize; ++i) {
        delete[] heapArray[i];
    }
    delete[] heapArray;
}

void MinHeap::insertKey(int u, int v, int weight) {
    if (heapSize == capacity) {
        cout << "Heap overflow!" << endl;
        return;
    }

    // Insert the new key at the end
    int i = heapSize++;
    heapArray[i][0] = u;
    heapArray[i][1] = v;
    heapArray[i][2] = weight;

    // Fix the min heap property if it is violated
    while (i != 0 && heapArray[i][2] < heapArray[(i - 1) / 2][2]) {
        swap(heapArray[i], heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int* MinHeap::extractMin() {
    if (heapSize <= 0) {
        return nullptr;
    }
    if (heapSize == 1) {
        --heapSize;
        return heapArray[0];
    }

    // Store the minimum value, and remove it from heap
    int* root = heapArray[0];
    heapArray[0] = heapArray[--heapSize];
    heapify(0);

    return root;
}

void MinHeap::heapify(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heapSize && heapArray[left][2] < heapArray[smallest][2]) {
        smallest = left;
    }
    if (right < heapSize && heapArray[right][2] < heapArray[smallest][2]) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(heapArray[idx], heapArray[smallest]);
        heapify(smallest);
    }
}

bool MinHeap::isEmpty() const {
    return heapSize == 0;
}
