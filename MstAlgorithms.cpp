#include "MstAlgorithms.h"
#include <limits>

void MstAlgorithms::primIncidenceMatrix(const IncidenceMatrix& graph, int** result, int& resultSize) {
    int vertices = graph.getVertices();
    int edges = graph.getEdges();
    const int** matrix = graph.getMatrix();

    int* key = new int[vertices];
    int* parent = new int[vertices];
    bool* inMST = new bool[vertices];

    for (int i = 0; i < vertices; ++i) {
        key[i] = std::numeric_limits<int>::max();
        parent[i] = -1;
        inMST[i] = false;
    }

    key[0] = 0;

    for (int count = 0; count < vertices - 1; ++count) {
        int minKey = std::numeric_limits<int>::max();
        int u = -1;

        for (int v = 0; v < vertices; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        for (int i = 0; i < edges; ++i) {
            int weight = matrix[u][i];
            if (weight != 0) {
                int v = -1;
                for (int j = 0; j < vertices; ++j) {
                    if (j != u && matrix[j][i] == -weight) {
                        v = j;
                        break;
                    }
                }
                if (v != -1 && !inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }
    }

    resultSize = vertices - 1;
    *result = new int[2 * resultSize];
    int k = 0;
    for (int i = 1; i < vertices; ++i) {
        (*result)[k++] = parent[i];
        (*result)[k++] = i;
    }

    delete[] key;
    delete[] parent;
    delete[] inMST;
}

void MstAlgorithms::primAdjacencyList(const AdjacencyList& graph, int** result, int& resultSize) {
    int vertices = graph.getVertices();
    int* key = new int[vertices];
    int* parent = new int[vertices];
    bool* inMST = new bool[vertices];

    for (int i = 0; i < vertices; ++i) {
        key[i] = std::numeric_limits<int>::max();
        parent[i] = -1;
        inMST[i] = false;
    }

    key[0] = 0;

    for (int count = 0; count < vertices - 1; ++count) {
        int minKey = std::numeric_limits<int>::max();
        int u = -1;

        for (int v = 0; v < vertices; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        AdjacencyList::Node* node = graph.getAdjacencyList()[u];
        while (node) {
            int v = node->edge.to;
            int weight = node->edge.weight;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
            node = node->next;
        }
    }

    resultSize = vertices - 1;
    *result = new int[2 * resultSize];
    int k = 0;
    for (int i = 1; i < vertices; ++i) {
        (*result)[k++] = parent[i];
        (*result)[k++] = i;
    }

    delete[] key;
    delete[] parent;
    delete[] inMST;
}
