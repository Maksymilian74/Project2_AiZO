#include "IncidenceMatrix.h"
#include <iostream>

IncidenceMatrix::IncidenceMatrix(int vertices) : vertices(vertices), edges(0), edgeCapacity(10) {
    // Alokacja macierzy incydencji
    matrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        matrix[i] = new int[edgeCapacity];
        for (int j = 0; j < edgeCapacity; ++j) {
            matrix[i][j] = 0;
        }
    }

    // Alokacja listy krawędzi
    edgeList = new int*[edgeCapacity];
    for (int i = 0; i < edgeCapacity; ++i) {
        edgeList[i] = new int[3]; // Każda krawędź to (u, v, weight)
    }
}

IncidenceMatrix::~IncidenceMatrix() {
    for (int i = 0; i < vertices; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < edgeCapacity; ++i) {
        delete[] edgeList[i];
    }
    delete[] edgeList;
}

void IncidenceMatrix::resizeMatrix() {
    for (int i = 0; i < vertices; ++i) {
        int* newRow = new int[edgeCapacity * 2];
        for (int j = 0; j < edgeCapacity; ++j) {
            newRow[j] = matrix[i][j];
        }
        for (int j = edgeCapacity; j < edgeCapacity * 2; ++j) {
            newRow[j] = 0;
        }
        delete[] matrix[i];
        matrix[i] = newRow;
    }
    edgeCapacity *= 2;
}

void IncidenceMatrix::resizeEdgeList() {
    int** newEdgeList = new int*[edgeCapacity * 2];
    for (int i = 0; i < edgeCapacity; ++i) {
        newEdgeList[i] = edgeList[i];
    }
    for (int i = edgeCapacity; i < edgeCapacity * 2; ++i) {
        newEdgeList[i] = new int[3];
    }
    delete[] edgeList;
    edgeList = newEdgeList;
    edgeCapacity *= 2;
}

void IncidenceMatrix::addEdge(int u, int v, int weight) {
    if (u >= vertices || v >= vertices) {
        std::cerr << "Error: Vertex index out of bounds." << std::endl;
        return;
    }

    if (edges == edgeCapacity) {
        resizeMatrix();
        resizeEdgeList();
    }

    // Dodanie krawędzi do listy krawędzi
    edgeList[edges][0] = u;
    edgeList[edges][1] = v;
    edgeList[edges][2] = weight;

    // Ustawienie wartości w macierzy incydencji
    matrix[u][edges] = weight;
    matrix[v][edges] = -weight;

    edges++;
}

void IncidenceMatrix::display() const {
    std::cout << "Incidence Matrix:" << std::endl;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < edges; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void IncidenceMatrix::displayEdges() const {
    std::cout << "Edge List:" << std::endl;
    for (int i = 0; i < edges; ++i) {
        std::cout << "Edge " << i << ": (" << edgeList[i][0] << ", " << edgeList[i][1] << ") Weight: " << edgeList[i][2] << std::endl;
    }
}

int IncidenceMatrix::getVertices() const {
    return vertices;
}

int IncidenceMatrix::getEdges() const {
    return edges;
}

const int** IncidenceMatrix::getMatrix() const {
    return const_cast<const int**>(matrix);
}

const int** IncidenceMatrix::getEdgeList() const {
    return const_cast<const int**>(edgeList);
}
