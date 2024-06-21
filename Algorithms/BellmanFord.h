/*
 * Klasa BellmanFord odpowiedzialna jest za
 * implementacje algorytmu Bellmana-Forda
 * dla reprezentacji macierzy incydencji i listy sasiedztwa
 */

#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "../Structures/IncidenceMatrix.h"
#include "../Structures/AdjacencyList.h"
#include "../Structures/Array.h"

class BellmanFord {
public:
    // Metoda odpowiedzialna za uruchumienie algorytmu dla macierzy incydencji
    static Array<int> runIncidenceMatrix(IncidenceMatrix &matrix, int startingVertex, int endingVertex);

    // Metoda odpowiedzialna za uruchumienie algorytmu dla listy sasiedztwa
    static Array<int> runAdjacencyList(AdjacencyList &list, int startingVertex, int endingVertex);

};

#endif
