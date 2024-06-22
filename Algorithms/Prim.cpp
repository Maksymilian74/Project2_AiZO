#include "Prim.h"
#include "../Structures/MinHeap.h"
#include "../Structures/Array.cpp"

using namespace std;

// Algorytm Prima dla macierzy incydencji
IncidenceMatrix Prim::runIncidenceMatrix(IncidenceMatrix &matrix) {
    int vertexes = matrix.getVertices();
    int maxEdges = vertexes -1;
    int edges = matrix.getEdges();

    IncidenceMatrix result(vertexes, maxEdges); // Macierz wynikowa
    Array<bool> visited(vertexes); // Tablica przechowujaca informacje o odwiedzeniu wierzcholka
    MinHeap minHeap(edges);
    Edge edge;

    for (int i = 0; i < vertexes; i++) {
        visited[i] = false;
    }

    visited[0] = true;
    int v = 0;

    for (int i = 0; i < vertexes - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int secondVertex = matrix.getSecondVertex(j, v);
            if (matrix.getWeight(v, j) > 0 && !visited[secondVertex]) {
                edge.startVertex = v;
                edge.endVertex = secondVertex;
                edge.weight = matrix.getWeight(v, j);
                minHeap.add(edge);
            }
        }

        do {
            edge = minHeap.root();
            minHeap.erase();
        } while (visited[edge.endVertex]);

        result.addEdge(edge.startVertex, edge.endVertex, edge.weight, false);
        visited[edge.endVertex] = true;
        v = edge.endVertex;
    }
    return result;
}

// Algorytm Prima dla listy sasiedztwa
AdjacencyList Prim::runAdjacencyList(AdjacencyList &list) {
    int vertexes = list.getVertices();
    int edges = list.getEdges();

    AdjacencyList result(vertexes);  // Lista wynikowa
    Array<bool> visited(vertexes);  // Tablica przechowujaca informacje o odwiedzeniu wierzcholka
    MinHeap minHeap(edges);
    Edge edge;

    for (int i = 0; i < vertexes; i++) {
        visited[i] = false;
    }

    visited[0] = true;
    int v = 0;

    for (int i = 0; i < vertexes - 1; i++) {
        for (Node *vertex = list.getList(v); vertex; vertex = vertex->next) {
            if (!visited[vertex->vertex]) {
                edge.startVertex = v;
                edge.endVertex = vertex->vertex;
                edge.weight = vertex->edge;
                minHeap.add(edge);
            }
        }

        do {
            edge = minHeap.root();
            minHeap.erase();
        } while (visited[edge.endVertex]);

        result.addEdgeUndirected(edge.startVertex, edge.endVertex, edge.weight);

        visited[edge.endVertex] = true;
        v = edge.endVertex;
    }

    return result;
}
