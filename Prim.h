#ifndef PRIM_H
#define PRIM_H

#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

class Prim {
public:
    static void runIncidenceMatrix(const IncidenceMatrix &graph);
    static void runAdjacencyList(const AdjacencyList &graph);
};

#endif // PRIM_H
