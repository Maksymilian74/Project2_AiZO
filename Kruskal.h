#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

class Kruskal {
public:
    static void runIncidenceMatrix(const IncidenceMatrix &graph);
    static void runAdjacencyList(const AdjacencyList &graph);

private:
    static int find(int parent[], int i);
    static void unionSets(int parent[], int rank[], int x, int y);
    static void sortEdges(int edges[][3], int edgeCount);
};

#endif // KRUSKAL_H
