#ifndef PRIM_H
#define PRIM_H

#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

class Prim {
public:
    static void runIncidenceMatrix(const IncidenceMatrix &graph, int* &parent, int* &key);
    static void runAdjacencyList(const AdjacencyList &graph, int* &parent, int* &key);
};

#endif // PRIM_H
