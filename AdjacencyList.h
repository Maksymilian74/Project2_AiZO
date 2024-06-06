#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

struct Edge {
    int to;      // Wierzchołek docelowy
    int weight;  // Waga krawędzi
};

class AdjacencyList {
private:
    int vertices;      // Liczba wierzchołków
    int edges;         // Liczba krawędzi
    struct Node {
        Edge edge;
        Node* next;
    };
    Node** adjList;    // Tablica wskaźników do list sąsiedztwa

public:
    AdjacencyList(int vertices);
    ~AdjacencyList();

    void addEdge(int from, int to, int weight);
    void display() const;
};

#endif
