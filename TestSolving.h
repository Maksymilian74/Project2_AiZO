#ifndef PROJEKT2_AIZO_TESTSOLVING_H
#define PROJEKT2_AIZO_TESTSOLVING_H

#include <chrono>
#include <string>
#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

using namespace std;

class TestSolving {
public:
    // Konstruktor
    TestSolving();

    // Destruktor
    ~TestSolving();

    // Metoda odpowiedzialna za wczytanie danych z pliku
    void loadDataFromFile(string fileToOpen);

    // Metoda odpowiedzialna za generowanie grafu
    void generateRandomGraph(int vertices, int density);

    // Metoda odpowiedzialna za wyswietlenie grafu
    void displayGraph();

    void algorithmPrim();

    void algorithmKruskal();

    void algorithmDijkstra();

    void algorithmFordBellman();

    void algorithmFordFulkerson();


private:
    IncidenceMatrix* incidenceMatrix; // Wskaźnik na macierz incydencji
    AdjacencyList* adjacencyDirectedList;     // Wskaźnik na listę sąsiedztwa
    AdjacencyList* adjacencyUndirectedList;     // Wskaźnik na listę sąsiedztwa

    int* parent;
    int* key;
};

#endif
