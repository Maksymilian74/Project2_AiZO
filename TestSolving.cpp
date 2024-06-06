#include "TestSolving.h"
#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

// Konstruktor
TestSolving::TestSolving() {

    // Inicjalizacja zmiennych do pomiaru czasu
    start = high_resolution_clock::now();
    stop = high_resolution_clock::now();
    time = 0;
    incidenceMatrix = nullptr;
    adjacencyDirectedList = nullptr;
    adjacencyUndirectedList = nullptr;
}

// Destruktor
TestSolving:: ~TestSolving() {
    delete incidenceMatrix;
    delete adjacencyDirectedList;
    delete adjacencyUndirectedList;
}


// Metoda odpowiedzialna za wczytanie danych z pliku do tablicy
void TestSolving::loadDataFromFile(string fileToOpen) {
    ifstream file(fileToOpen); // Tworzenie strumienia do odczytu danych z pliku
    if (!file.is_open()) {
        cout << "-------------------------------------------\n";
        cout << "Blad! Nie udalo sie otworzyc pliku.\n";
        return;
    }

    file.close();
}

// Metoda odpowiedzialna za wygenerowanie grafu
void TestSolving::generateRandomGraph(int vertices, int density) {
    // Tworzenie instancji macierzy incydencji
    incidenceMatrix = new IncidenceMatrix(vertices, 2 * vertices);

    // Dodawanie krawędzi do macierzy incydencji
    incidenceMatrix->addEdge(0, 1, 10);
    incidenceMatrix->addEdge(1, 2, 20);
    incidenceMatrix->addEdge(2, 0, 30);

    // Tworzenie instancji listy sąsiedztwa
    adjacencyDirectedList = new AdjacencyList(vertices);

    // Dodawanie krawędzi do listy sąsiedztwa
    adjacencyDirectedList->addEdge(0, 1, 10);
    adjacencyDirectedList->addEdge(1, 2, 20);
    adjacencyDirectedList->addEdge(2, 0, 30);
    adjacencyDirectedList->addEdge(2, 1, 40);

    // Tworzenie instancji listy sąsiedztwa
    adjacencyUndirectedList = new AdjacencyList(vertices);

    // Dodawanie krawędzi do listy sąsiedztwa
    adjacencyUndirectedList->addEdge(0, 1, 10);
    adjacencyUndirectedList->addEdge(1, 2, 20);
    adjacencyUndirectedList->addEdge(2, 0, 30);
    adjacencyUndirectedList->addEdge(2, 1, 40);
}

// Metoda odpowiedzialna za wyswietlenie grafu
void TestSolving::displayGraph() {
    if (incidenceMatrix != nullptr) {
        std::cout << std::endl << "Incidence Matrix:" << std::endl;
        incidenceMatrix->display();
    }  else {
        std::cout << "No matrix to display." << std::endl;
    }

    if (adjacencyDirectedList != nullptr) {
        std::cout << std::endl << "Adjacency Directed Graph List:" << std::endl;
        adjacencyDirectedList->display();
    } else {
        std::cout << "No list to display." << std::endl;
    }

    if (adjacencyUndirectedList != nullptr) {
        std::cout << std::endl << "Adjacency Undirected Graph List:" << std::endl;
        adjacencyUndirectedList->display();
    } else {
        std::cout << "No list to display." << std::endl;
    }
}

void TestSolving::algorithmPrim() {

}

void TestSolving::algorithmKruskal() {

}

void TestSolving::algorithmDijkstra() {

}

void TestSolving::algorithmFordBellman() {

}

void TestSolving::algorithmFordFulkerson() {

}


