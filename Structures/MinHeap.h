/*
 * Klasa MinHeap odpowiedzialna jest za
 * implementacje kopca minimalnego
 *
 */

#ifndef MINHEAP_H
#define MINHEAP_H

#include "Array.h"

struct Edge {
    int startVertex;
    int endVertex;
    int weight;

    Edge(int u = 0, int v = 0, int w = 0) : startVertex(u), endVertex(v), weight(w) {}
};

class MinHeap {
public:
    MinHeap(int edges);
    ~MinHeap();
    MinHeap(const MinHeap& other);
    MinHeap& operator=(const MinHeap& other);

    Edge front() const;
    void push(const Edge& edge);
    void pop();
    bool empty() const { return currentSize == 0; }

private:
    Array<Edge> heap;
    int currentSize;

    void heapifyUp(int index);
    void heapifyDown(int index);
};

#endif
