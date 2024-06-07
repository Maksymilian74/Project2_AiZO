#ifndef MSTALGORITHMS_H
#define MSTALGORITHMS_H

#include "IncidenceMatrix.h"
#include "AdjacencyList.h"
#include "Quicksort.h"


class MstAlgorithms {
public:
    static void primIncidenceMatrix(const IncidenceMatrix& graph, int** result, int& resultSize);
    static void primAdjacencyList(const AdjacencyList& graph, int** result, int& resultSize);
    static void kruskalIncidenceMatrix(const IncidenceMatrix& graph, int** result, int& resultSize);
    static void kruskalAdjacencyList(const AdjacencyList& graph, int** result, int& resultSize);

private:
    static int find(int parent[], int i);
    static void unionSets(int parent[], int rank[], int x, int y);
};

#endif

