#include "Kruskal.h"
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

// Funkcja pomocnicza do znalezienia zestawu elementu i (zastosowanie ścieżkowej kompresji)
int Kruskal::find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

// Funkcja pomocnicza do połączenia dwóch zestawów x i y (zastosowanie unii przez rangę)
void Kruskal::unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// Funkcja pomocnicza do sortowania krawędzi na podstawie ich wag
void Kruskal::sortEdges(int edges[][3], int edgeCount) {
    for (int i = 0; i < edgeCount - 1; ++i) {
        for (int j = 0; j < edgeCount - i - 1; ++j) {
            if (edges[j][2] > edges[j + 1][2]) {
                int tempSrc = edges[j][0];
                int tempDest = edges[j][1];
                int tempWeight = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = tempSrc;
                edges[j + 1][1] = tempDest;
                edges[j + 1][2] = tempWeight;
            }
        }
    }
}

void Kruskal::runIncidenceMatrix(const IncidenceMatrix &graph) {
    int vertices = graph.getVertices();
    int edges = graph.getEdges();
    const int** edgeList = graph.getEdgeList();

    // Tworzenie tablicy krawędzi
    int (*edgesArray)[3] = new int[edges][3];
    for (int i = 0; i < edges; ++i) {
        edgesArray[i][0] = edgeList[i][0];
        edgesArray[i][1] = edgeList[i][1];
        edgesArray[i][2] = abs(edgeList[i][2]);
    }

    // Sortowanie krawędzi na podstawie ich wag
    sortEdges(edgesArray, edges);

    // Alokacja pamięci na rodzica i rangę dla Union-Find
    int* parent = new int[vertices];
    int* rank = new int[vertices];

    for (int i = 0; i < vertices; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    cout << "Edge \tWeight\n";
    for (int i = 0; i < edges; ++i) {
        int x = find(parent, edgesArray[i][0]);
        int y = find(parent, edgesArray[i][1]);

        if (x != y) {
            cout << edgesArray[i][0] << " - " << edgesArray[i][1] << "\t" << edgesArray[i][2] << "\n";
            unionSets(parent, rank, x, y);
        }
    }

    delete[] edgesArray;
    delete[] parent;
    delete[] rank;
}

void Kruskal::runAdjacencyList(const AdjacencyList &graph) {
    int vertices = graph.getVertices();
    int edges = 0;
    AdjacencyList::Node** adjList = graph.getAdjacencyList();

    // Zliczanie liczby krawędzi
    for (int u = 0; u < vertices; ++u) {
        AdjacencyList::Node* node = adjList[u];
        while (node != nullptr) {
            edges++;
            node = node->next;
        }
    }

    // Tworzenie tablicy krawędzi
    int (*edgesArray)[3] = new int[edges][3];
    int index = 0;
    for (int u = 0; u < vertices; ++u) {
        AdjacencyList::Node* node = adjList[u];
        while (node != nullptr) {
            edgesArray[index][0] = u;
            edgesArray[index][1] = node->edge.to;
            edgesArray[index][2] = node->edge.weight;
            index++;
            node = node->next;
        }
    }

    // Sortowanie krawędzi na podstawie ich wag
    sortEdges(edgesArray, edges);

    // Alokacja pamięci na rodzica i rangę dla Union-Find
    int* parent = new int[vertices];
    int* rank = new int[vertices];

    for (int i = 0; i < vertices; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    cout << "Edge \tWeight\n";
    for (int i = 0; i < edges; ++i) {
        int x = find(parent, edgesArray[i][0]);
        int y = find(parent, edgesArray[i][1]);

        if (x != y) {
            cout << edgesArray[i][0] << " - " << edgesArray[i][1] << "\t" << edgesArray[i][2] << "\n";
            unionSets(parent, rank, x, y);
        }
    }

    delete[] edgesArray;
    delete[] parent;
    delete[] rank;
}
