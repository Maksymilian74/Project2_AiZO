#include "Prim.h"
#include <iostream>
#include <limits>

using namespace std;

void Prim::runIncidenceMatrix(const IncidenceMatrix &graph) {
    int vertices = graph.getVertices();
    int edges = graph.getEdges();
    const int** matrix = graph.getMatrix();

    int* parent = new int[vertices];
    int* key = new int[vertices];
    bool* inMST = new bool[vertices];

    for (int i = 0; i < vertices; ++i) {
        key[i] = numeric_limits<int>::max();
        inMST[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; ++count) {
        int minKey = numeric_limits<int>::max();
        int u = -1;

        for (int v = 0; v < vertices; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

//        for (int v = 0; v < vertices; ++v) {
//            for (int e = 0; e < edges; ++ e) {
//                int weight = abs(matrix[v][e]);
//                if (weight > 0 && !inMST[v] && weight < key[v]) {
//                    parent[v] = u;
//                    key[v] = weight;
//                }
//            }
//        }

        for (int e = 0; e < edges; ++e) {
            if (matrix[u][e] != 0) {
                for (int v = 0; v < vertices; ++v) {
                    if (v != u && matrix[v][e] != 0 && !inMST[v]) {
                        int weight = abs(matrix[u][e]);
                        if (weight < key[v]) {
                            parent[v] = u;
                            key[v] = weight;
                        }
                    }
                }
            }
        }

    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < vertices; ++i) {
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
    }

    delete[] parent;
    delete[] key;
    delete[] inMST;
}

void Prim::runAdjacencyList(const AdjacencyList &graph) {
    int vertices = graph.getVertices();
    AdjacencyList::Node** adjList = graph.getAdjacencyList();

    int* parent = new int[vertices];
    int* key = new int[vertices];
    bool* inMST = new bool[vertices];

    for (int i = 0; i < vertices; ++i) {
        key[i] = numeric_limits<int>::max();
        inMST[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; ++count) {
        int minKey = numeric_limits<int>::max();
        int u = -1;

        for (int v = 0; v < vertices; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        AdjacencyList::Node* node = adjList[u];
        while (node != nullptr) {
            int v = node->edge.to;
            int weight = node->edge.weight;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
            node = node->next;
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < vertices; ++i) {
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
    }

    delete[] parent;
    delete[] key;
    delete[] inMST;
}
