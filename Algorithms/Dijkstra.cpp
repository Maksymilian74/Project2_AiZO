#include "Dijkstra.h"
#include "../Structures/Array.cpp"

// Algorytm Dijkstry dla macierzy incydencji
Array<int> Dijkstra::runIncidenceMatrix(IncidenceMatrix &matrix, int startingVertex, int endingVertex) {
    int vertexes = matrix.getVertices();
    int edges = matrix.getEdges();

    Array<bool> visited(vertexes);
    Array<int> parent(vertexes);
    Array<int> distance(vertexes);

    for (int i = 0; i < vertexes; i++) {
        visited[i] = false;
        parent[i] = -1;
        distance[i] = INT_MAX;
    }

    distance[startingVertex] = 0;

    for (int i = 0; i < vertexes; i++) {
        int minimum = minimumVertex(distance, visited, vertexes);
        visited[minimum] = true;

        for (int j = 0; j < edges; j++) {
            if (matrix.getWeight(minimum, j) > 0 && !visited[matrix.getSecVertex(j)] &&
                distance[minimum] != INT_MAX) {
                int dist = distance[minimum] + matrix.getWeight(minimum, j);
                if (dist < distance[matrix.getSecVertex(j)]) {
                    distance[matrix.getSecVertex(j)] = dist;
                    parent[matrix.getSecVertex(j)] = minimum;
                }
            }
        }
    }

    if (distance[endingVertex] == INT_MAX) {
        std::cout << "Brak sciezki" << std::endl << std::endl;
        return Array<int>();
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


// Algorytm Dijkstry dla listy sasiedztwa
Array<int> Dijkstra::runAdjacencyList(AdjacencyList &list, int startingVertex, int endingVertex) {
    int vertexes = list.getVertices();

    Array<bool> visited(vertexes);
    Array<int> parent(vertexes);
    Array<int> distance(vertexes);

    for (int i = 0; i < vertexes; i++) {
        visited[i] = false;
        parent[i] = -1;
        distance[i] = INT_MAX;
    }

    distance[startingVertex] = 0;

    for (int i = 0; i < vertexes; i++) {
        int minimum = minimumVertex(distance, visited, vertexes);
        visited[minimum] = true;

        for (Node *vertex = list.getList(minimum); vertex; vertex = vertex->next) {
            if (!visited[vertex->vertex] && distance[minimum] != INT_MAX && (distance[vertex->vertex] > distance[minimum] + vertex->edge)) {
                distance[vertex->vertex] = distance[minimum] + vertex->edge;
                parent[vertex->vertex] = minimum;
            }
        }
    }

    if (distance[endingVertex] == INT_MAX) {
        std::cout << "Brak sciezki" << std::endl << std::endl;
        return Array<int>();
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

// Metoda odpowiedzialna za znalezienie wierzcholka o najmniejszej odleglosci
int Dijkstra::minimumVertex(Array<int> &dist, Array<bool> &visited, int n) {
    int min = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && (min == -1 || dist[i] < dist[min])) {
            min = i;
        }
    }
    return min;
}