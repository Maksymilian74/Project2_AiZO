#include "IncidenceMatrix.h"
#include <iostream>
#include <iomanip> // dodajemy nagłówek dla manipulatorów strumieniowych

IncidenceMatrix::IncidenceMatrix(int vertices, int edges) : vertices(vertices), edges(edges) {
    currentEdge = 0;
    // Alokacja macierzy incydencji
    matrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        matrix[i] = new int[edges];
        for (int j = 0; j < edges; ++j) {
            matrix[i][j] = 0;
        }
    }

    // Alokacja listy krawędzi
    edgeList = new int*[edges];
    for (int i = 0; i < edges; ++i) {
        edgeList[i] = new int[3]; // Każda krawędź to (u, v, weight)
    }
    std::cout << "IncidenceMatrix object created with " << vertices << " vertices and " << edges << " edges." << std::endl;
}

IncidenceMatrix::~IncidenceMatrix() {
    for (int i = 0; i < vertices; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < edges; ++i) {
        delete[] edgeList[i];
    }
    delete[] edgeList;
    std::cout << "IncidenceMatrix object destroyed." << std::endl;
}

void IncidenceMatrix::addEdge(int u, int v, int weight) {
    if (u >= vertices || v >= vertices) {
        std::cerr << "Error: Vertex index out of bounds." << std::endl;
        return;
    }

    std::cout << "numer: " << currentEdge << std::endl;
    if (currentEdge > edges) {
        std::cerr << "Error: Exceeded maximum number of edges." << std::endl;
        return;
    }
    std::cout << "Edge added from " << u << " to " << v << " with weight " << weight << "." << std::endl;
    // Dodanie krawędzi do listy krawędzi
    edgeList[currentEdge][0] = u;
    edgeList[currentEdge][1] = v;
    edgeList[currentEdge][2] = weight;

    // Ustawienie wartości w macierzy incydencji
    matrix[u][currentEdge] = weight;
    matrix[v][currentEdge] = -weight;

    currentEdge++;
}

void IncidenceMatrix::display() const {
    // Wyświetlanie nagłówka z numerami krawędzi
    std::cout << "      ";
    for (int j = 0; j < edges; ++j) {
        std::cout << std::setw(3) << j << " ";
    }
    std::cout << std::endl;

    // Wyświetlanie linii oddzielającej nagłówek
    std::cout << "    +";
    for (int j = 0; j < edges; ++j) {
        std::cout << "----";
    }
    std::cout << std::endl;

    // Wyświetlanie macierzy incydencji z numerami wierzchołków
    for (int i = 0; i < vertices; ++i) {
        std::cout << std::setw(3) << i << " | ";
        for (int j = 0; j < edges; ++j) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
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
