#ifndef UNIONFIND_H
#define UNIONFIND_H

#include "../Structures/MinHeap.h"

struct UnionNode {
    int parent; // Rodzic wezla
    int rank;   // Ranga seta
};

class UnionFind {
private:
    UnionNode *set;         //
    int numVertices;      // Liczba wierzcholkow

public:
    UnionFind(int numVertices);  // Konstruktor
    ~UnionFind();                  // Destruktor
    void makeSet(int vertex);      // Tworzenie seta
    int findSet(int vertex);       // Zwraca rodzica seta
    void unionSets(Edge &edge); // Laczy dwa sety
};
#endif
