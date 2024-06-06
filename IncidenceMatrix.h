#ifndef PROJEKT2_AIZO_INCIDENCEMATRIX_H
#define PROJEKT2_AIZO_INCIDENCEMATRIX_H

class IncidenceMatrix {
private:
    int vertices;
    int edges;
    int edgeCapacity; // Pojemność dla krawędzi
    int **matrix; // Dynamicznie alokowana macierz incydencji
    int **edgeList; // Dynamicznie alokowana lista krawędzi

    void resizeMatrix(); // Metoda do rozszerzania macierzy incydencji
    void resizeEdgeList(); // Metoda do rozszerzania listy krawędzi

public:
    IncidenceMatrix(int vertices);
    ~IncidenceMatrix();
    void addEdge(int u, int v, int weight);
    void display() const;
    void displayEdges() const;
    int getVertices() const;
    int getEdges() const;
    const int** getMatrix() const;
    const int** getEdgeList() const;
};

#endif //PROJEKT2_AIZO_INCIDENCEMATRIX_H
