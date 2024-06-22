#include "SimulationSolving.h"
#include "../Algorithms/Prim.h"
#include "../Algorithms/Kruskal.h"
#include "../Algorithms/Dijkstra.h"
#include "../Algorithms/BellmanFord.h"
#include "../Utils/FillStructure.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Konstruktor
SimulationSolving::SimulationSolving() {
    incidenceUndirectedMatrix = nullptr;
    incidenceDirectedMatrix = nullptr;
    adjacencyDirectedList = nullptr;
    adjacencyUndirectedList = nullptr;
    time = 0;
}

// Destruktor
SimulationSolving::~SimulationSolving() {
    delete incidenceUndirectedMatrix;
    delete incidenceDirectedMatrix;
    delete adjacencyDirectedList;
    delete adjacencyUndirectedList;
}

// Metoda do testowania konkretnego algorytmu
void SimulationSolving::testAlgorithm(int algorithmType) {
    int verticesArray[] = {5,10, 20, 50, 100, 200, 500};
    int densityArray[] = {25, 50, 99};
    int iterations = 20;

    for (int density : densityArray) {
        switch (density) {
            case 25:
                cout << "\nGestosc: 25%\n";
                break;
            case 50:
                cout << "\nGestosc: 50%\n";
                break;
            case 99:
                cout << "\nGestosc: 99%\n";
                break;
            default:
                cout << "Nieprawidlowa gestosc!\n";
                break;
        }

        for (int vertices : verticesArray) {
            cout << "\nWierzcholek: " << vertices << endl;

            time = 0;
            for (int i = 0; i < iterations; i++) {
                generateRandomGraph(vertices, density, algorithmType);
                time += runAlgorithm(algorithmType, vertices);
            }
            cout << "Algorytm " << algorithmType << " Sredni czas: " << time / iterations << " ms\n";
        }
    }
}

// Metoda do uruchamiania konkretnego algorytmu i mierzenia jego czasu wykonania
double SimulationSolving::runAlgorithm(int algorithmType, int vertices) {
    double timeIteration = 0;
    switch (algorithmType) {
        case 1:
            start = high_resolution_clock::now();
            Prim::runIncidenceMatrix(*incidenceUndirectedMatrix);
            stop = high_resolution_clock::now();
            break;
        case 2:
            start = high_resolution_clock::now();
            Prim::runAdjacencyList(*adjacencyUndirectedList);
            stop = high_resolution_clock::now();
            break;
        case 3:
            start = high_resolution_clock::now();
            Kruskal::runIncidenceMatrix(*incidenceUndirectedMatrix);
            stop = high_resolution_clock::now();
            break;
        case 4:
            start = high_resolution_clock::now();
            Kruskal::runAdjacencyList(*adjacencyUndirectedList);
            stop = high_resolution_clock::now();
            break;
        case 5:
            start = high_resolution_clock::now();
            Dijkstra::runIncidenceMatrix(*incidenceDirectedMatrix, 0, vertices - 1);
            stop = high_resolution_clock::now();
            break;
        case 6:
            start = high_resolution_clock::now();
            Dijkstra::runAdjacencyList(*adjacencyDirectedList, 0, vertices - 1);
            stop = high_resolution_clock::now();
            break;
        case 7:
            start = high_resolution_clock::now();
            BellmanFord::runIncidenceMatrix(*incidenceDirectedMatrix, 0, vertices - 1);
            stop = high_resolution_clock::now();
            break;
        case 8:
            start = high_resolution_clock::now();
            BellmanFord::runAdjacencyList(*adjacencyDirectedList, 0, vertices - 1);
            stop = high_resolution_clock::now();
            break;
        default:
            cout << "Nieznany algorytm!\n";
            break;
    }

    timeIteration = duration_cast<duration<double, milli>>(stop - start).count();
    return timeIteration;
}

// Metoda do generowania losowego grafu
void SimulationSolving::generateRandomGraph(int vertices, int density, int algorithmType) {
    if(algorithmType == 1 || algorithmType == 2 || algorithmType == 3 || algorithmType == 4 ) {
        // Usuwanie istniejacej macierzy, jesli istnieje
        if (incidenceUndirectedMatrix != nullptr) {
            delete incidenceUndirectedMatrix;
            incidenceUndirectedMatrix = nullptr;
        }

        // Usuwanie istniejacej listy sasiedztwa dla grafu nieskierowanego, jesli istnieje
        if (adjacencyUndirectedList != nullptr) {
            delete adjacencyUndirectedList;
            adjacencyUndirectedList = nullptr;
        }

        // Obliczenie liczby krawedzi na podstawie gestosci
        int maxEdges = vertices * (vertices - 1) / 2;
        int numEdges = (density * maxEdges) / 100;

        // Sprawdzenie, czy maksymalna liczba krawedzi dla zadanej gestosci jest wieksza od vertices - 1
        if (numEdges < vertices - 1) {
            numEdges = vertices - 1; // Ustawienie minimalnej liczby krawedzi potrzebnej do utworzenia grafu spojnego
        }

        incidenceUndirectedMatrix = new IncidenceMatrix(vertices, numEdges); // maksymalna ilosc krawedzi
        adjacencyUndirectedList = new AdjacencyList(vertices);

        FillStructure::generateRandomUndirectedGraph( *incidenceUndirectedMatrix, *adjacencyUndirectedList, vertices, density);

    } else {
        // Usuwanie istniejacej macierzy, jesli istnieje
        if (incidenceDirectedMatrix != nullptr) {
            delete incidenceDirectedMatrix;
            incidenceDirectedMatrix = nullptr;
        }

        // Usuwanie istniejacej listy sasiedztwa dla grafu skierowanego, jesli istnieje
        if (adjacencyDirectedList != nullptr) {
            delete adjacencyDirectedList;
            adjacencyDirectedList = nullptr;
        }

        // Obliczenie liczby krawedzi na podstawie gestosci
        int maxEdges = vertices * (vertices - 1);
        int numEdges = (density * maxEdges) / 100;

        // Sprawdzenie, czy maksymalna liczba krawedzi dla zadanej gestosci jest wieksza od vertices - 1
        if (numEdges < vertices - 1) {
            numEdges = vertices - 1; // Ustawienie minimalnej liczby krawedzi potrzebnej do utworzenia grafu spojnego
        }

        incidenceDirectedMatrix = new IncidenceMatrix(vertices, numEdges); // maksymalna ilosc krawedzi
        adjacencyDirectedList = new AdjacencyList(vertices);

        FillStructure::generateRandomDirectedGraph( *incidenceDirectedMatrix, *adjacencyDirectedList, vertices, density);
    }
}
