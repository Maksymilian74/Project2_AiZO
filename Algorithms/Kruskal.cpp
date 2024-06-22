#include "Kruskal.h"

using namespace std;

// Algorytm Kruskala dla macierzy incydencji
IncidenceMatrix Kruskal::runIncidenceMatrix(IncidenceMatrix &matrix) {
    int vertexes = matrix.getVertices();
    int maxEdges = vertexes -1;
    int edges = matrix.getEdges();

    IncidenceMatrix result(vertexes, maxEdges); // Macierz wynikowa
    MinHeap minHeap(2 * edges);
    Edge edge;
    UnionFind set(vertexes);

    for (int i = 0; i < vertexes; i++) {
        set.makeSet(i);
    }

    for (int i = 0; i < vertexes; i++) {
        for (int j = 0; j < edges; j++) {
            if (matrix.getWeight(i, j) > 0) {
                edge.startVertex = i;
                edge.endVertex = matrix.getSecondVertex(j, i);
                edge.weight = matrix.getWeight(i, j);
                minHeap.add(edge);
            }
        }
    }

    for (int i = 0; i < vertexes - 1; i++) {
        do {
            edge = minHeap.root();
            minHeap.erase();
        } while (set.findSet(edge.startVertex) == set.findSet(edge.endVertex));

        result.addEdge(edge.startVertex, edge.endVertex, edge.weight, false);
        set.unionSets(edge);
    }
    return result;
}

// Algorytm Kruskala dla listy sasiedztwa
AdjacencyList Kruskal::runAdjacencyList(AdjacencyList &list) {
    int vertexes = list.getVertices();
    int edges = list.getEdges();

    AdjacencyList result(vertexes);
    MinHeap minHeap(2 * edges);
    Edge edge;
    UnionFind set(vertexes);

    for (int i = 0; i < vertexes; i++) {
        set.makeSet(i);
    }

    for (int i = 0; i < vertexes; i++) {
        for (Node *vertex = list.getList(i); vertex; vertex = vertex->next) {
            edge.startVertex = i;
            edge.endVertex = vertex->vertex;
            edge.weight = vertex->edge;
            minHeap.add(edge);
        }
    }

    for (int i = 0; i < vertexes - 1; i++) {
        do {
            edge = minHeap.root();
            minHeap.erase();
        } while (set.findSet(edge.startVertex) == set.findSet(edge.endVertex));

        result.addEdgeUndirected(edge.startVertex, edge.endVertex, edge.weight);
        set.unionSets(edge);
    }

    return result;
}
