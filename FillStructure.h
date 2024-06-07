#ifndef FILLSTRUCTURE_H
#define FILLSTRUCTURE_H

#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

class FillStructure {
public:
    static void generateRandomGraph(IncidenceMatrix &matrix, AdjacencyList &directedList, AdjacencyList &undirectedList, int vertices, int density);
};

#endif

