#ifndef INCIDENCEMATRIX_H
#define INCIDENCEMATRIX_H

class IncidenceMatrix {
private:
    int vertices;    // Liczba wierzchołkow
    int edges;       // Liczba krawedzi
    int currentEdge; // Liczba krawedzi aktualnie
    int** matrix;    // Macierz incydencji
    int** edgeList;  // Lista krawedzi

public:
    IncidenceMatrix(int vertices, int edges);
    ~IncidenceMatrix();

    void addEdge(int u, int v, int weight);
    void display() const;
    void displayEdges() const;

    int getVertices() const;
    int getEdges() const;
    const int** getMatrix() const;
    const int** getEdgeList() const;
};

#endif // INCIDENCEMATRIX_H

