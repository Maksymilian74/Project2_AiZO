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



