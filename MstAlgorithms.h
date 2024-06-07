#ifndef MSTALGORITHMS_H
#define MSTALGORITHMS_H

#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

class MstAlgorithms {
public:
    static void primIncidenceMatrix(const IncidenceMatrix& graph, int** result, int& resultSize);
    static void primAdjacencyList(const AdjacencyList& graph, int** result, int& resultSize);
};

#endif

