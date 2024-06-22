/*
 * Klasa SimulationSolving odpowiedzialna jest za
 * implementacje podmenu do automatycznego badania
 * oraz mierzenia czasow wykonania algorytmow
 */

#ifndef SIMULATIONSOLVING_H
#define SIMULATIONSOLVING_H

#include "../Structures/IncidenceMatrix.h"
#include "../Structures/AdjacencyList.h"
#include <chrono>

class SimulationSolving {
private:
    IncidenceMatrix* incidenceUndirectedMatrix;      // Wskaznik na macierz incydencji
    IncidenceMatrix* incidenceDirectedMatrix;        // Wskaznik na macierz incydencji
    AdjacencyList* adjacencyDirectedList;            // Wskaznik na liste sasiedztwa dla grafu skierowanego
    AdjacencyList* adjacencyUndirectedList;          // Wskaznik na liste sasiedztwa dla grafu nieskierowanego
    std::chrono::high_resolution_clock::time_point start, stop;  // Punkty czasowe do mierzenia czasu wykonania
    double time;  // Zmienna do przechowywania zmierzonego czasu

public:
    // Konstruktor
    SimulationSolving();

    // Destruktor
    ~SimulationSolving();

    // Metoda do testowania konkretnego algorytmu
    void testAlgorithm(int algorithmType);

private:
    // Metoda do uruchamiania konkretnego algorytmu i mierzenia czasu jego wykonania
    double runAlgorithm(int algorithmType, int vertices);

    // Metoda do generowania losowego grafu
    void generateRandomGraph(int vertices, int density, int algorithmType);
};

#endif
