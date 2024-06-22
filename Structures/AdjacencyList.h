/*
 * Klasa AdjancencyList odpowiedzialna jest za
 * implementacje listy sasiedztwa
 *
 */

#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

// Struktura reprezentujaca pojedynczy wezel listy sasiedztwa
struct Node {
    int vertex;
    int edge;
    Node* next; // Wskaznik do nastepnego wezla
};

// Klasa reprezentujaca liste sasiedztwa grafu
class AdjacencyList {
private:
    int vertices;      // Liczba wierzcholkow
    int edges;         // Liczba krawedzi
    int totalWeight;   // Waga calego grafu
    Node** adjList;    // Tablica wskaznikow do list sasiedztwa

public:
    // Konstruktor
    AdjacencyList(int vertices);

    // Destruktor
    ~AdjacencyList();

    // Metoda dodajaca skierowana krawedz do grafu
    void addEdgeDirected(int from, int to, int weight);

    // Metoda dodajaca nieskierowana krawedz do grafu
    void addEdgeUndirected(int from, int to, int weight);

    // Metoda wyswietlajaca liste sasiedztwa
    void display() const;

    // Metoda zwracajaca liczbe wierzcholkow w grafie
    int getVertices() const;

    // Metoda zwracajaca liczbe krawedzi w grafie
    int getEdges() const;

    // Metoda zwracajaca liste dla danego wierzcholka
    Node* getList(int vertex);
};

#endif
