#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

class BellmanFord {
public:
    static void runIncidenceMatrix(const IncidenceMatrix &graph, int startVertex, int endVertex);
    static void runAdjacencyList(const AdjacencyList &graph, int startVertex, int endVertex);

private:
    static void printPath(int parent[], int vertex);
};

#endif // BELLMANFORD_H
