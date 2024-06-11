#include "TestSolving.h"
#include "FillStructure.h"
#include "Prim.h"
#include "Kruskal.h"
#include "Dijkstra.h"
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
    std::cout << "TestSolving object destroyed." << std::endl;
}


// Metoda odpowiedzialna za wczytanie danych z pliku do tablicy
void TestSolving::loadDataFromFile(string fileToOpen) {
    ifstream file(fileToOpen); // Tworzenie strumienia do odczytu danych z pliku
    if (!file.is_open()) {
        cout << "-------------------------------------------\n";
        cout << "Blad! Nie udalo sie otworzyc pliku.\n";
        return;
    }

    int numEdges, numVertices;
    file >> numEdges >> numVertices; // Wczytanie liczby krawędzi i wierzchołków

    // Usuwanie istniejącej macierzy, jeśli istnieje
    if (incidenceMatrix != nullptr) {
        cout << "Deleting existing incidence matrix." << endl;
        delete incidenceMatrix;
        incidenceMatrix = nullptr;
        std::cout << "IncidenceMatrix object deleted." << std::endl;
    }

    // Tworzenie instancji listy sąsiedztwa dla grafu skierowanego
    if (adjacencyDirectedList != nullptr) {
        cout << "Deleting existing incidence list." << endl;
        delete adjacencyDirectedList;
        adjacencyDirectedList = nullptr;
        std::cout << "AdjacencyDirectedList object deleted." << std::endl;
    }

    // Tworzenie instancji listy sąsiedztwa dla grafu nieskierowanego
    if (adjacencyUndirectedList != nullptr) {
        cout << "Deleting existing incidence list." << endl;
        delete adjacencyUndirectedList;
        adjacencyUndirectedList = nullptr;
        std::cout << "AdjacencyUndirectedList object deleted." << std::endl;
    }

    // Tworzenie instancji macierzy incydencji
    incidenceMatrix = new IncidenceMatrix(numVertices, numEdges);
    std::cout << "New IncidenceMatrix object created." << std::endl;

    adjacencyDirectedList = new AdjacencyList(numVertices);
    std::cout << "New AdjacencyDirectedList object created." << std::endl;

    adjacencyUndirectedList = new AdjacencyList(numVertices);
    std::cout << "New AdjacencyUndirectedList object created." << std::endl;

    int startVertex, endVertex, weight;
    // Wczytywanie danych o krawędziach i dodawanie ich do macierzy incydencji
    for (int i = 0; i < numEdges; ++i) {
        file >> startVertex >> endVertex >> weight;
        std::cout << "Wpisywanie" << std::endl;
        incidenceMatrix->addEdge(startVertex, endVertex, weight);
        adjacencyDirectedList->addEdge(startVertex, endVertex, weight);
        adjacencyUndirectedList->addEdge(startVertex, endVertex, weight);
        adjacencyUndirectedList->addEdge(endVertex, startVertex, weight);
    }

    file.close();
}


// Metoda odpowiedzialna za wygenerowanie grafu
void TestSolving::generateRandomGraph(int vertices, int density) {
    // Usuwanie istniejącej macierzy, jeśli istnieje
    if (incidenceMatrix != nullptr) {
        delete incidenceMatrix;
        incidenceMatrix = nullptr;
    }

    // Usuwanie istniejącej listy sąsiedztwa dla grafu skierowanego, jeśli istnieje
    if (adjacencyDirectedList != nullptr) {
        delete adjacencyDirectedList;
        adjacencyDirectedList = nullptr;
    }

    // Usuwanie istniejącej listy sąsiedztwa dla grafu nieskierowanego, jeśli istnieje
    if (adjacencyUndirectedList != nullptr) {
        delete adjacencyUndirectedList;
        adjacencyUndirectedList = nullptr;
    }

    // Obliczenie liczby krawędzi na podstawie gęstości
    int maxEdges = vertices * (vertices - 1) / 2;
    int numEdges = (density * maxEdges) / 100;

    // Tworzenie instancji macierzy incydencji
    incidenceMatrix = new IncidenceMatrix(vertices, numEdges);

    // Tworzenie instancji listy sąsiedztwa dla grafu skierowanego
    adjacencyDirectedList = new AdjacencyList(vertices);

    // Tworzenie instancji listy sąsiedztwa dla grafu nieskierowanego
    adjacencyUndirectedList = new AdjacencyList(vertices);

    // Wygenerowanie losowego grafu za pomocą metody z klasy FillStructure
    FillStructure::generateRandomGraph(*incidenceMatrix, *adjacencyDirectedList, *adjacencyUndirectedList, vertices, density);
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
    if (incidenceMatrix != nullptr) {
        cout << "Running Prim's algorithm using incidence matrix:" << endl;
        Prim::runIncidenceMatrix(*incidenceMatrix);
    } else {
        cout << "No incidence matrix available." << endl;
    }

    if (adjacencyUndirectedList != nullptr) {
        cout << "Running Prim's algorithm using adjacency list:" << endl;
        Prim::runAdjacencyList(*adjacencyUndirectedList);
    } else {
        cout << "No adjacency list available." << endl;
    }
}

void TestSolving::algorithmKruskal() {
    if (incidenceMatrix != nullptr) {
        cout << "Running Kruskal's algorithm using incidence matrix:" << endl;
        Kruskal::runIncidenceMatrix(*incidenceMatrix);
    } else {
        cout << "No incidence matrix available." << endl;
    }

    if (adjacencyUndirectedList != nullptr) {
        cout << "Running Kruskal's algorithm using adjacency list:" << endl;
        Kruskal::runAdjacencyList(*adjacencyUndirectedList);
    } else {
        cout << "No adjacency list available." << endl;
    }
}

void TestSolving::algorithmDijkstra() {
    int startVertex, endVertex;
    cout << "Enter start vertex: ";
    cin >> startVertex;
    cout << "Enter end vertex: ";
    cin >> endVertex;

    if (incidenceMatrix != nullptr) {
        cout << "Running Dijkstra's algorithm using incidence matrix:" << endl;
        Dijkstra::runIncidenceMatrix(*incidenceMatrix, startVertex, endVertex);
    } else {
        cout << "No incidence matrix available." << endl;
    }

    if (adjacencyDirectedList != nullptr) {
        cout << "Running Dijkstra's algorithm using adjacency list:" << endl;
        Dijkstra::runAdjacencyList(*adjacencyDirectedList, startVertex, endVertex);
    } else {
        cout << "No adjacency list available." << endl;
    }
}

void TestSolving::algorithmFordBellman() {

}

void TestSolving::algorithmFordFulkerson() {

}

