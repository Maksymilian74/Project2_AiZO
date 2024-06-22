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
    // Konstruktor
    MinHeap(int edges);

    // Destruktor
    ~MinHeap();

    // Konstruktor kopiujacy
    MinHeap(const MinHeap& other);

    // Operator przypisania
    MinHeap& operator=(const MinHeap& other);

    // Metoda zwracajaca korzen kopca
    Edge root() const;

    // Metoda dodajaca krawedz do kopca
    void add(const Edge& edge);

    // Metoda usuwajaca krawedz z kopca
    void erase();

    // Metoda sprawdzajaca czy kopiec jest pusty
    bool empty() const { return currentSize == 0; }

private:
    Array<Edge> heap;  // Tablica reprezentujaca kopiec
    int currentSize;   // Aktualny rozmiar kopca

    // Metoda odpowiedzialna za naprawe kopca w gore
    void heapifyUp(int index);

    // Metoda odpowiedzialna za naprawe kopca w dol
    void heapifyDown(int index);
};

#endif
