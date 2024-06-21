/*
 * Klasa Kruskal odpowiedzialna jest za
 * implementacje algorytmu Kruskala
 * dla reprezentacji macierzy incydencji i listy sasiedztwa
 */

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../Structures/IncidenceMatrix.h"
#include "../Structures/AdjacencyList.h"
#include "../Structures/MinHeap.h"
#include "../Utils/UnionFind.h"

class Kruskal {
public:
    // Metoda odpowiedzialna za uruchumienie algorytmu dla macierzy incydencji
    static IncidenceMatrix runIncidenceMatrix(IncidenceMatrix &matrix);

    // Metoda odpowiedzialna za uruchumienie algorytmu dla listy sasiedztwa
    static AdjacencyList runAdjacencyList(AdjacencyList &list);

};

#endif
