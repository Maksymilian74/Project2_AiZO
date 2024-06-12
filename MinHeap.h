#ifndef MINHEAP_H
#define MINHEAP_H

class MinHeap {
private:
    int** heapArray;
    int capacity;
    int heapSize;

    void heapify(int idx);

public:
    MinHeap(int capacity);
    ~MinHeap();

    void insertKey(int u, int v, int weight);
    int* extractMin();
    bool isEmpty() const;
    void decreaseKey(int u, int new_weight);
};

#endif // MINHEAP_H
