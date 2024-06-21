/*
 * Klasa IncidenceMAtrix odpowiedzialna jest za
 * implementacje macierzy incydencji
 *
 */

#ifndef INCIDENCEMATRIX_H
#define INCIDENCEMATRIX_H

class IncidenceMatrix {
private:
    int vertices;    // Liczba wierzcholkow
    int edges;       // Liczba krawedzi
    int currentEdge; // Liczba krawedzi aktualnie
    int** matrix;    // Macierz incydencji

public:
    // Konstruktor
    IncidenceMatrix(int vertices, int edges);

    // Destruktor
    ~IncidenceMatrix();

    // Metoda do dodawania krawedzi do macierzy incydencji
    void addEdge(int u, int v, int weight, bool directed);

    // Metoda do wyswietlania macierzy incydencji
    void display() const;

    // Metoda zwracajaca liczbe wierzcholkow
    int getVertices() const;

    // Metoda zwracajaca wage krawedzi
    int getWeight(int u, int x);

    // Metoda zwracajaca liczbe krawedzi
    int getEdges() const;

    // Metoda zwracajaca drugi wierzcholek danej krawedzi
    int getSecondVertex(int j, int u);

    // Metoda zwracajaca drugi wierzcholek danej krawedzi
    int getSecVertex(int j);

    // Metoda sprawdzajaca istnienie krawedzi
    bool checkEdge(int, int);

};

#endif

