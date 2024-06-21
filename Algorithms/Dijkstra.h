/*
 * Klasa Dijkstra odpowiedzialna jest za
 * implementacje algorytmu Dijkstry
 * dla reprezentacji macierzy incydencji i listy sasiedztwa
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../Structures/IncidenceMatrix.h"
#include "../Structures/AdjacencyList.h"
#include "../Structures/Array.h"

class Dijkstra {
public:
    // Metoda odpowiedzialna za uruchumienie algorytmu dla macierzy incydencji
    static Array<int> runIncidenceMatrix(IncidenceMatrix &matrix, int startingVertex, int endingVertex);

    // Metoda odpowiedzialna za uruchumienie algorytmu dla listy sasiedztwa
    static Array<int> runAdjacencyList(AdjacencyList &list, int startingVertex, int endingVertex);

private:
    static int minimumVertex(Array<int> &dist, Array<bool> &visited, int n);
};

#endif
