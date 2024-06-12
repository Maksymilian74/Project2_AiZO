#ifndef SIMULATIONSOLVING_H
#define SIMULATIONSOLVING_H

#include "IncidenceMatrix.h"
#include "AdjacencyList.h"
#include <chrono>

class SimulationSolving {
private:
    IncidenceMatrix* incidenceMatrix;
    AdjacencyList* adjacencyDirectedList;
    AdjacencyList* adjacencyUndirectedList;
    std::chrono::high_resolution_clock::time_point start, stop;
    double time;

public:
    SimulationSolving();
    ~SimulationSolving();
    void testAlgorithms();
    void testAlgorithm(int algorithmType);

private:
    double runAlgorithm(int algorithmType, int vertices);
    void generateRandomGraph(int vertices, int density);

    int* parent;
    int* key;
};

#endif // SIMULATIONSOLVING_H
