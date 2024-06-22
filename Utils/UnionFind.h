/*
 * Klasa UnionFind odpowiedzialna jest za
 * zarzadzanie zbiorami rozlacznymi
 *
 */

#ifndef UNIONFIND_H
#define UNIONFIND_H

#include "../Structures/MinHeap.h"

// Struktura reprezentujaca wezel w Union-Find
struct UnionNode {
    int parent; // Rodzic wezla
    int rank;   // Ranga seta
};

class UnionFind {
private:
    UnionNode *set;       // Tablica przechowujaca wezly
    int numVertices;      // Liczba wierzcholkow

public:
    UnionFind(int numVertices);      // Konstruktor
    ~UnionFind();                    // Destruktor
    void makeSet(int vertex);        // Metoda tworzaca set dla danego wierzcholka
    int findSet(int vertex);  // Metoda zwracajaca rodzica seta dla danego wierzcholka
    void unionSets(Edge &edge);     // Metoda laczaca dwa sety na podstawie krawedzi
};
#endif
