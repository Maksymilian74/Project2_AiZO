#include "AdjacencyList.h"
#include <iostream>

AdjacencyList::AdjacencyList(int vertices)
        : vertices(vertices), edges(0) {
    adjList = new Node*[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjList[i] = nullptr;
    }
}

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

void AdjacencyList::addEdge(int from, int to, int weight) {
    if (from >= vertices || to >= vertices) {
        std::cerr << "Invalid vertices!" << std::endl;
        return;
    }

    Node* newNode = new Node;
    newNode->edge = {to, weight};
    newNode->next = adjList[from];
    adjList[from] = newNode;
    edges++;
}

void AdjacencyList::display() const {
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Vertex " << i << ":";
        Node* current = adjList[i];
        while (current) {
            std::cout << " -> (to: " << current->edge.to << ", weight: " << current->edge.weight << ")";
            current = current->next;
        }
        std::cout << std::endl;
    }
}
