#include "FillStructure.h"
#include <cstdlib>
#include <ctime>

// Metoda odpowiedzialna za generowanie losowego grafu
void FillStructure::generateRandomDirectedGraph(IncidenceMatrix &directedMatrix, AdjacencyList &directedList, int vertices, int density) {
    std::srand(std::time(0));

    // Tworzenie minimalnego drzewa rozpinajacego (MST)
    for (int i = 1; i < vertices; ++i) {
        int u = i;
        int v = std::rand() % i;
        int weight = std::rand() % 100 + 1; // Losowa waga krawedzi
        directedMatrix.addEdge(u, v, weight, true);
        directedList.addEdge(u, v, weight);
    }

    // Obliczenie maksymalnej liczby krawedzi
    int maxEdges = vertices * (vertices - 1);
    int requiredEdges = (density * maxEdges) / 100;

    // Dodanie pozostalych krawedzi do osiagniecia wymaganej gestosci
    int edgeCount = vertices - 1; // Bo juz mamy (vertices - 1) krawedzi w MST
    while (edgeCount < requiredEdges) {
        int u = std::rand() % vertices;
        int v = std::rand() % vertices;
        if (u != v && !directedMatrix.checkEdge(u,v)) {
            int weight = std::rand() % 100 + 1;
            directedMatrix.addEdge(u, v, weight, true);
            directedList.addEdge(u, v, weight);
            edgeCount++;
        }
    }
}

// Metoda odpowiedzialna za generowanie losowego grafu
void FillStructure::generateRandomUndirectedGraph(IncidenceMatrix &undirectedMatrix, AdjacencyList &undirectedList, int vertices, int density) {
    std::srand(std::time(0));

    // Tworzenie minimalnego drzewa rozpinajacego (MST)
    for (int i = 1; i < vertices; ++i) {
        int u = i;
        int v = std::rand() % i;
        int weight = std::rand() % 100 + 1; // Losowa waga krawedzi
        undirectedMatrix.addEdge(u, v, weight, false);
        undirectedList.addEdge(u, v, weight);
        undirectedList.addEdge(v, u, weight);
    }

    // Obliczenie maksymalnej liczby krawedzi
    int maxEdges = vertices * (vertices - 1) / 2;
    int requiredEdges = (density * maxEdges) / 100;

    // Dodanie pozostalych krawedzi do osiagniecia wymaganej gestosci
    int edgeCount = vertices - 1; // Bo juz mamy (vertices - 1) krawedzi w MST
    while (edgeCount < requiredEdges) {
        int u = std::rand() % vertices;
        int v = std::rand() % vertices;
        if (u != v && !undirectedMatrix.checkEdge(u,v)) {
            int weight = std::rand() % 100 + 1;
            undirectedMatrix.addEdge(u, v, weight, false);
            undirectedList.addEdge(u, v, weight);
            undirectedList.addEdge(v, u, weight);
            edgeCount++;
        }
    }
}

