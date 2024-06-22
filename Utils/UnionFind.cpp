#include "unionFind.h"

// Konstruktor
UnionFind::UnionFind(int numVertices) {
    set = new UnionNode[numVertices];
    this->numVertices = numVertices;
}

// Destruktor
UnionFind::~UnionFind() {
    delete[] set;
}

// Metoda odpowiedzialna za tworzenie seta dla danego wierzcholka
void UnionFind::makeSet(int vertex) {
    set[vertex].parent = vertex;
    set[vertex].rank = 0;
}

// Metoda odpowiedzialna za szukanie rodzica seta dla zadanego wierzcholka
int UnionFind::findSet(int vertex) {
    if (set[vertex].parent != vertex) {
        set[vertex].parent = findSet(set[vertex].parent);
    }
    return set[vertex].parent;
}

// Metoda odpowiedzialna za polaczenie dwoch setow
void UnionFind::unionSets(Edge &edge) {
    int set1, set2;

    set1 = findSet(edge.startVertex);
    set2 = findSet(edge.endVertex);

    if (set1 != set2) {
        if (set[set1].rank > set[set2].rank) {
            set[set2].parent = set1;
        } else {
            set[set1].parent = set2;
            if (set[set1].rank == set[set2].rank) {
                set[set2].rank++;
            }
        }
    }
}

