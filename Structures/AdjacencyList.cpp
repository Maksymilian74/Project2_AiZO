#include "AdjacencyList.h"
#include <iostream>

// Konstruktor
AdjacencyList::AdjacencyList(int vertices)
        : vertices(vertices), edges(0), totalWeight(0) {
    adjList = new Node*[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjList[i] = nullptr;
    }
}

// Destruktor
AdjacencyList::~AdjacencyList() {
    for (int i = 0; i < vertices; ++i) {
        Node* current = adjList[i];
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
    delete[] adjList;
}

// Metoda odpowiedzialna za dodanie skierowanej krawedzi do listy sasiedztwa
void AdjacencyList::addEdgeDirected(int from, int to, int weight) {
    if (from >= vertices || to >= vertices) {
        std::cerr << "Zla liczba wierzcholkow!" << std::endl;
        return;
    }

    totalWeight += weight;
    Node* newNode = new Node;
    newNode->vertex = to;
    newNode->edge = weight;
    newNode->next = adjList[from];
    adjList[from] = newNode;
    edges++;
}

// Metoda odpowiedzialna za dodanie nieskierowanej krawedzi do listy sasiedztwa
void AdjacencyList::addEdgeUndirected(int from, int to, int weight) {
    addEdgeDirected(from, to, weight);
    addEdgeDirected(to, from, weight);
    totalWeight -= weight;
}

// Metoda odpowiedzialna za wyswietlanie listy sasiedztwa
void AdjacencyList::display() const {
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Wierzcholek " << i << ":";
        Node* current = adjList[i];
        while (current) {
            std::cout << " (" << current->vertex << ";" << current->edge << ")";
            current = current->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "Waga calego grafu: " << totalWeight << std::endl;
}

// Getter liczby wierzcholkow
int AdjacencyList::getVertices() const {
    return vertices;
}

// Getter liczby krawedzi
int AdjacencyList::getEdges() const {
    return edges;
}

// Getter listy dla danego wierzcholka
Node* AdjacencyList::getList(int vertex) { return adjList[vertex]; }