#include "IncidenceMatrix.h"
#include <iostream>
#include <iomanip>

// Konstruktor
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

}

// Destruktor
IncidenceMatrix::~IncidenceMatrix() {
    for (int i = 0; i < vertices; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

}

// Metoda odpowiedzialna za dodanie krawedzi do macierzy incydencji
void IncidenceMatrix::addEdge(int u, int v, int weight, bool directed) {
    if (u >= vertices || v >= vertices) {
        std::cerr << "Blad: Wierzcholek poza zakresem" << std::endl;
        return;
    }

    if (currentEdge > edges) {
        std::cerr << "Blad: Osiagnieto minimalna liczbe krawedzi" << std::endl;
        return;
    }

    // Ustawienie wartosci w macierzy incydencji
    matrix[u][currentEdge] = weight;
    if(directed == 1)
        matrix[v][currentEdge] = -weight;
    else
        matrix[v][currentEdge] = weight;

    currentEdge++;
}

void IncidenceMatrix::display() const {
    // Wyswietlanie nagłowka z numerami krawedzi
    std::cout << "      ";
    for (int j = 0; j < edges; ++j) {
        std::cout << std::setw(3) << j << " ";
    }
    std::cout << std::endl;

    // Wyswietlanie linii oddzielajacej naglowek
    std::cout << "    +";
    for (int j = 0; j < edges; ++j) {
        std::cout << "----";
    }
    std::cout << std::endl;

    // Wyswietlanie macierzy incydencji z numerami wierzcholkow
    for (int i = 0; i < vertices; ++i) {
        std::cout << std::setw(3) << i << " | ";
        for (int j = 0; j < edges; ++j) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Getter liczby wierzcholkow
int IncidenceMatrix::getVertices() const {
    return vertices;
}

// Getter liczby krawedzi
int IncidenceMatrix::getEdges() const {
    return edges;
}

int IncidenceMatrix::getWeight(int u, int x) {
    return matrix[u][x];
}

int IncidenceMatrix::getSecondVertex(int j, int u) {
    if (j > edges - 1) return -1;

    for (int i = 0; i < vertices; i++) {
        if (i == u) continue;
        if (matrix[i][j] > 0)
            return i;
    }
    return -1;
}

int IncidenceMatrix::getSecVertex(int j) {
    if (j > edges - 1) return -1;

    for (int i = 0; i < vertices; i++) {
        if (matrix[i][j] < 0)
            return i;
    }
    return -1;
}

int IncidenceMatrix::getFirstVertex(int j) {
    if (j > edges - 1) return -1;

    for (int i = 0; i < vertices; i++) {
        if (matrix[i][j] > 0)
            return i;
    }
    return -1;
}

//Metoda sprawdzajaca istnienie krawedzi
bool IncidenceMatrix::checkEdge(int v1, int v2){
    if (v1 >= vertices || v2 >= vertices) {
        std::cerr << "Blad: Wierzcholek poza zakresem" << std::endl;
        return false;
    }

    for (int i = 0; i < currentEdge; ++i) {
        if (matrix[v1][i] != 0 && matrix[v2][i] != 0) {
            // Sprawdzenie grafu nieskierowanego
            if (matrix[v1][i] == matrix[v2][i]) {
                return true;
            }
            // Sprawdzenie grafu skierowanego
            if ((matrix[v1][i] > 0 && matrix[v2][i] < 0) || (matrix[v1][i] < 0 && matrix[v2][i] > 0)) {
                return true;
            }
        }
    }
    return false;
}

