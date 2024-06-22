#include "BellmanFord.h"
#include <limits>

// Algorytm BellmanaForda dla macierzy incydencji
Array<int> BellmanFord::runIncidenceMatrix(IncidenceMatrix &matrix, int startingVertex, int endingVertex) {
    int vertexes = matrix.getVertices();
    int edges = matrix.getEdges();

    Array<int> distance(vertexes);
    Array<int> parent(vertexes);
    bool stop;

    for (int i = 0; i < vertexes; i++) {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    distance[startingVertex] = 0;

    for (int i = 0; i < vertexes - 1; i++) {
        stop = true;
        for (int j = 0; j < edges; j++) {
            int u = matrix.getFirstVertex(j);
            int v = matrix.getSecVertex(j);
            int w = matrix.getWeight(u, j);
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                parent[v] = u;
                stop = false;
            }
        }
        if (stop) break;
    }

    Array<int> tmpPath(vertexes);
    int pathIndex = 0;
    int tmp = endingVertex;
    while (tmp != -1) {
        tmpPath[pathIndex++] = tmp;
        tmp = parent[tmp];
    }

    for (int i = 0; i < pathIndex / 2; ++i) {
        std::swap(tmpPath[i], tmpPath[pathIndex - i - 1]);
    }

    Array<int> result(pathIndex + 1);
    for (int i = 0; i < pathIndex; ++i) {
        result[i] = tmpPath[i];
    }
    result[pathIndex] = distance[endingVertex];

    return result;
}

// Algorytm BellmanaForda dla listy sasiedztwa
Array<int> BellmanFord::runAdjacencyList(AdjacencyList &list, int startingVertex, int endingVertex) {
    int vertexes = list.getVertices();

    int edges = list.getEdges();
    Array<int> distance(vertexes);
    Array<int> parent(vertexes);
    bool stop;

    for (int i = 0; i < vertexes; i++) {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    distance[startingVertex] = 0;

    for (int i = 0; i < vertexes - 1; i++) {
        stop = true;
        for (int j = 0; j < vertexes; j++) {
            for (Node *vertex = list.getList(j); vertex; vertex = vertex->next) {
                if ((distance[j] != INT_MAX) && (distance[vertex->vertex] > distance[j] + vertex->edge)) {
                    distance[vertex->vertex] = distance[j] + vertex->edge;
                    parent[vertex->vertex] = j;
                    stop = false;
                }
            }
        }
        if (stop) break;
    }

    Array<int> tmpPath(vertexes);
    int pathIndex = 0;
    int tmp = endingVertex;
    while (tmp != -1) {
        tmpPath[pathIndex++] = tmp;
        tmp = parent[tmp];
    }

    for (int i = 0; i < pathIndex / 2; ++i) {
        std::swap(tmpPath[i], tmpPath[pathIndex - i - 1]);
    }

    Array<int> result(pathIndex + 1);
    for (int i = 0; i < pathIndex; ++i) {
        result[i] = tmpPath[i];
    }
    result[pathIndex] = distance[endingVertex];

    return result;
}
