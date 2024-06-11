#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

class Dijkstra {
public:
    static void runIncidenceMatrix(const IncidenceMatrix &graph, int startVertex, int endVertex);
    static void runAdjacencyList(const AdjacencyList &graph, int startVertex, int endVertex);

private:
    static void printPath(int parent[], int vertex);
    static int minDistance(int dist[], bool sptSet[], int vertices);
};

#endif // DIJKSTRA_H
