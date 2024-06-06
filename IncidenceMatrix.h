#ifndef INCIDENCEMATRIX_H
#define INCIDENCEMATRIX_H

class IncidenceMatrix {
private:
    int vertices;    // Liczba wierzchołków
    int edges;       // Liczba krawędzi
    int** matrix;    // Macierz incydencji
    int** edgeList;  // Lista krawędzi

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

