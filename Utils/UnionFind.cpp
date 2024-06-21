#include "unionFind.h"

UnionFind::UnionFind(int numVertices) {
    set = new UnionNode[numVertices];
    this->numVertices = numVertices;
}

UnionFind::~UnionFind() {
    delete[] set;
}

void UnionFind::makeSet(int vertex) {
    set[vertex].parent = vertex;
    set[vertex].rank = 0;
}

int UnionFind::findSet(int vertex) {
    if (set[vertex].parent != vertex) {
        set[vertex].parent = findSet(set[vertex].parent);
    }
    return set[vertex].parent;
}

void UnionFind::unionSets(Edge &edge) {
    int root1, root2;

    root1 = findSet(edge.startVertex);
    root2 = findSet(edge.endVertex);

    if (root1 != root2) {
        if (set[root1].rank > set[root2].rank) {
            set[root2].parent = root1;
        } else {
            set[root1].parent = root2; 
            if (set[root1].rank == set[root2].rank) {
                set[root2].rank++;
            }
        }
    }
}

