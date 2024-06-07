#include "FillStructure.h"
#include <cstdlib>
#include <ctime>

void FillStructure::generateRandomGraph(IncidenceMatrix &matrix, AdjacencyList &directedList, AdjacencyList &undirectedList, int vertices, int density) {
    std::srand(std::time(0));

    // Tworzenie minimalnego drzewa rozpinającego (MST)
    for (int i = 1; i < vertices; ++i) {
        int u = i;
        int v = std::rand() % i;
        int weight = std::rand() % 100 + 1; // Losowa waga krawędzi
        matrix.addEdge(u, v, weight);
        directedList.addEdge(u, v, weight);
        undirectedList.addEdge(u, v, weight);
        undirectedList.addEdge(v, u, weight);
    }

    // Obliczenie maksymalnej liczby krawędzi
    int maxEdges = vertices * (vertices - 1) / 2;
    int requiredEdges = (density * maxEdges) / 100;

    // Dodanie pozostałych krawędzi do osiągnięcia wymaganej gęstości
    int edgeCount = vertices - 1; // Bo już mamy (vertices - 1) krawędzi w MST
    while (edgeCount < requiredEdges) {
        int u = std::rand() % vertices;
        int v = std::rand() % vertices;
        if (u != v) {
            int weight = std::rand() % 100 + 1;
            matrix.addEdge(u, v, weight);
            directedList.addEdge(u, v, weight);
            undirectedList.addEdge(u, v, weight);
            undirectedList.addEdge(v, u, weight);
            edgeCount++;
        }
    }
}

