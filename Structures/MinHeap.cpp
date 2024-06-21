#include "minheap.h"
#include <stdexcept>
#include "Array.cpp"

using namespace std;

MinHeap::MinHeap(int edges) : heap(edges), currentSize(0) {}

MinHeap::MinHeap(const MinHeap& other) : heap(other.heap), currentSize(other.currentSize) {}

MinHeap::~MinHeap() {}

MinHeap& MinHeap::operator=(const MinHeap& other) {
    if (this != &other) {
        heap = other.heap;
        currentSize = other.currentSize;
    }
    return *this;
}

void MinHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index].weight >= heap[parent].weight) {
            break;
        }
        swap(heap[index], heap[parent]);
        index = parent;
    }
}

void MinHeap::heapifyDown(int index) {
    int tmp = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < currentSize && heap[leftChild].weight < heap[tmp].weight) {
        tmp = leftChild;
    }

    if (rightChild < currentSize && heap[rightChild].weight < heap[tmp].weight) {
        tmp = rightChild;
    }

    if (tmp != index) {
        swap(heap[index], heap[tmp]);
        heapifyDown(tmp);
    }
}

void MinHeap::push(const Edge& edge) {
    if (currentSize == heap.size()) {
        heap.resize(heap.size() * 2);
    }
    heap[currentSize] = edge;
    heapifyUp(currentSize);
    currentSize++;
}

void MinHeap::pop() {
    if (currentSize == 0) {
        return;
    }
    currentSize--;
    heap[0] = heap[currentSize];
    heapifyDown(0);
}

Edge MinHeap::front() const {
    if (currentSize == 0) {
        throw out_of_range("Kolejka jest pusta");
    }
    return heap[0];
}