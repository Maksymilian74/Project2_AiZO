#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

struct Edge {
    int to;      // Wierzchołek docelowy
    int weight;  // Waga krawędzi
};

class AdjacencyList {
public:
    struct Node {
        Edge edge;
        Node* next;
    };

private:
    int vertices;      // Liczba wierzchołków
    int edges;         // Liczba krawędzi
    Node** adjList;    // Tablica wskaźników do list sąsiedztwa

public:
    AdjacencyList(int vertices);
    ~AdjacencyList();

    void addEdge(int from, int to, int weight);
    void display() const;
    int getVertices() const;
    int getEdges() const;
    Node** getAdjacencyList() const;
};

#endif
