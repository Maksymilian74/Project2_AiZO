/*
 * Klasa Prim odpowiedzialna jest za
 * implementacje algorytmu Prima
 * dla reprezentacji macierzy incydencji i listy sasiedztwa
 */

#ifndef PRIM_H
#define PRIM_H

#include "../Structures/IncidenceMatrix.h"
#include "../Structures/AdjacencyList.h"
#include "../Structures/MinHeap.h"
#include "../Structures/Array.h"

class Prim {
public:
    // Metoda odpowiedzialna za uruchumienie algorytmu dla macierzy incydencji
    static IncidenceMatrix runIncidenceMatrix(IncidenceMatrix &matrix);

    // Metoda odpowiedzialna za uruchumienie algorytmu dla listy sasiedztwa
    static AdjacencyList runAdjacencyList(AdjacencyList &graph);
};

#endif
