#ifndef PROJEKT2_AIZO_TESTSOLVING_H
#define PROJEKT2_AIZO_TESTSOLVING_H

#include <chrono>
#include <string>
#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

using namespace std;
using namespace std::chrono;

class TestSolving {
public:
    // Konstruktor
    TestSolving();

    // Destruktor
    ~TestSolving();

    // Metoda odpowiedzialna za wczytanie danych z pliku
    void loadDataFromFile(string fileToOpen);

    // Metoda odpowiedzialna za generowanie grafu
    void generateRandomGraph(int size, int fillingMethod);

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
    std::chrono::high_resolution_clock::time_point start; // Zmienna przechowujaca początek pomiaru czasu
    std::chrono::high_resolution_clock::time_point stop; // Zmienna przechowujaca koniec pomiaru czasu
    double time; // Zmienna przechowujaca czas sortowania
};

#endif
