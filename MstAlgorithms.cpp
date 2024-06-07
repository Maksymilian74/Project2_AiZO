#include "MstAlgorithms.h"
#include "Quicksort.h"
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

int MstAlgorithms::find(int parent[], int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void MstAlgorithms::unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void MstAlgorithms::kruskalIncidenceMatrix(const IncidenceMatrix& graph, int** result, int& resultSize) {
    int vertices = graph.getVertices();
    int edges = graph.getEdges();
    const int** edgeList = graph.getEdgeList();

    Edges* edgeArray = new Edges[edges];
    for (int i = 0; i < edges; ++i) {
        edgeArray[i].from = edgeList[i][0];
        edgeArray[i].to = edgeList[i][1];
        edgeArray[i].weight = edgeList[i][2];
    }

    QuickSort::sort(edgeArray, 0, edges - 1);

    int* parent = new int[vertices];
    int* rank = new int[vertices];

    for (int i = 0; i < vertices; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    resultSize = 0;
    *result = new int[2 * (vertices - 1)];
    for (int i = 0; i < edges; ++i) {
        int rootU = find(parent, edgeArray[i].from);
        int rootV = find(parent, edgeArray[i].to);

        if (rootU != rootV) {
            (*result)[2 * resultSize] = edgeArray[i].from;
            (*result)[2 * resultSize + 1] = edgeArray[i].to;
            resultSize++;
            unionSets(parent, rank, rootU, rootV);
        }
    }

    delete[] edgeArray;
    delete[] parent;
    delete[] rank;
}

void MstAlgorithms::kruskalAdjacencyList(const AdjacencyList& graph, int** result, int& resultSize) {
    int vertices = graph.getVertices();
    int edges = graph.getEdges();

    Edges* edgeArray = new Edges[edges];
    int edgeIndex = 0;

    AdjacencyList::Node** adjList = graph.getAdjacencyList();
    for (int i = 0; i < vertices; ++i) {
        AdjacencyList::Node* currentNode = adjList[i];
        while (currentNode != nullptr) {
            if (i < currentNode->edge.to) {
                edgeArray[edgeIndex].from = i;
                edgeArray[edgeIndex].to = currentNode->edge.to;
                edgeArray[edgeIndex].weight = currentNode->edge.weight;

                edgeIndex++;
            }
            currentNode = currentNode->next;
        }
    }

    QuickSort::sort(edgeArray, 0, edges - 1);

    int* parent = new int[vertices];
    int* rank = new int[vertices];

    for (int i = 0; i < vertices; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    resultSize = 0;
    *result = new int[2 * (vertices - 1)];
    for (int i = 0; i < edges; ++i) {
        int rootU = find(parent, edgeArray[i].from);
        int rootV = find(parent, edgeArray[i].to);

        if (rootU != rootV) {
            (*result)[2 * resultSize] = edgeArray[i].from;
            (*result)[2 * resultSize + 1] = edgeArray[i].to;
            resultSize++;
            unionSets(parent, rank, rootU, rootV);
        }
    }

    delete[] edgeArray;
    delete[] parent;
    delete[] rank;
}
