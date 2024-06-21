/*
 * Klasa FillStructure odpowiedzialna jest za
 * implementacje generowania losowego grafu
 * o zadaniej liczbie wierzcholkow i gestosci
 */

#ifndef FILLSTRUCTURE_H
#define FILLSTRUCTURE_H

#include "../Structures/IncidenceMatrix.h"
#include "../Structures/AdjacencyList.h"

class FillStructure {
public:
    // Metoda odpowiedzialna za generowanie losowego grafu
    static void generateRandomDirectedGraph(IncidenceMatrix &directedMatrix, AdjacencyList &directedList, int vertices, int density);

    // Metoda odpowiedzialna za generowanie losowego grafu
    static void generateRandomUndirectedGraph(IncidenceMatrix &undirectedMatrix, AdjacencyList &undirectedList, int vertices, int density);
};

#endif

