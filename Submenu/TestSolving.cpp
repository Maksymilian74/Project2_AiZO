#include "TestSolving.h"
#include "../Utils/FillStructure.h"
#include "../Structures/Array.h"
#include "../Structures/Array.cpp"
#include "../Algorithms/Prim.h"
#include "../Algorithms/Kruskal.h"
#include "../Algorithms/Dijkstra.h"
#include "../Algorithms/BellmanFord.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace std::chrono;

// Konstruktor
TestSolving::TestSolving() {
    incidenceUndirectedMatrix = nullptr;
    incidenceDirectedMatrix = nullptr;
    adjacencyDirectedList = nullptr;
    adjacencyUndirectedList = nullptr;
}

// Destruktor
TestSolving::~TestSolving() {
    delete incidenceUndirectedMatrix;
    delete incidenceDirectedMatrix;
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

    int numEdges, numVertices;
    file >> numEdges >> numVertices; // Wczytanie liczby krawędzi i wierzchołkow

    // Usuwanie istniejacej macierzy, jesli istnieje
    if (incidenceUndirectedMatrix != nullptr) {
        delete incidenceUndirectedMatrix;
        incidenceUndirectedMatrix = nullptr;
    }

    // Usuwanie istniejacej macierzy, jesli istnieje
    if (incidenceDirectedMatrix != nullptr) {
        delete incidenceDirectedMatrix;
        incidenceDirectedMatrix = nullptr;
    }

    // Tworzenie instancji listy sasiedztwa dla grafu skierowanego
    if (adjacencyDirectedList != nullptr) {
        delete adjacencyDirectedList;
        adjacencyDirectedList = nullptr;
    }

    // Tworzenie instancji listy sasiedztwa dla grafu nieskierowanego
    if (adjacencyUndirectedList != nullptr) {
        delete adjacencyUndirectedList;
        adjacencyUndirectedList = nullptr;
    }

    // Tworzenie instancji macierzy incydencji
    incidenceUndirectedMatrix = new IncidenceMatrix(numVertices, numEdges);

    // Tworzenie instancji macierzy incydencji
    incidenceDirectedMatrix = new IncidenceMatrix(numVertices, numEdges);

    // Tworzenie instancji listy sasiedztwa dla grafu skierowanego
    adjacencyDirectedList = new AdjacencyList(numVertices);

    // Tworzenie instancji listy sasiedztwa dla grafu nieskierowanego
    adjacencyUndirectedList = new AdjacencyList(numVertices);

    int startVertex, endVertex, weight;
    // Wczytywanie danych o krawedziach i dodawanie ich do macierzy incydencji
    for (int i = 0; i < numEdges; ++i) {
        file >> startVertex >> endVertex >> weight;
        incidenceUndirectedMatrix->addEdge(startVertex, endVertex, weight,false);
        incidenceDirectedMatrix->addEdge(startVertex, endVertex, weight,true);
        adjacencyDirectedList->addEdgeDirected(startVertex, endVertex, weight);
        adjacencyUndirectedList->addEdgeUndirected(startVertex, endVertex, weight);
    }
    file.close();
}

// Metoda odpowiedzialna za wygenerowanie grafu skierowanego
void TestSolving::generateRandomDirectedGraph(int vertices, int density) {
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

    // Tworzenie instancji macierzy incydencji
    incidenceDirectedMatrix = new IncidenceMatrix(vertices, numEdges);

    // Tworzenie instancji listy sasiedztwa dla grafu skierowanego
    adjacencyDirectedList = new AdjacencyList(vertices);

    // Wygenerowanie losowego grafu za pomoca metody z klasy FillStructure
    FillStructure::generateRandomDirectedGraph( *incidenceDirectedMatrix, *adjacencyDirectedList, vertices, density);
}

// Metoda odpowiedzialna za wygenerowanie grafu nieskierowanego
void TestSolving::generateRandomUndirectedGraph(int vertices, int density) {
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

    // Tworzenie instancji macierzy incydencji
    incidenceUndirectedMatrix = new IncidenceMatrix(vertices, numEdges);

    // Tworzenie instancji listy sasiedztwa dla grafu nieskierowanego
    adjacencyUndirectedList = new AdjacencyList(vertices);

    // Wygenerowanie losowego grafu za pomocą metody z klasy FillStructure
    FillStructure::generateRandomUndirectedGraph(*incidenceUndirectedMatrix, *adjacencyUndirectedList, vertices, density);
}

// Metoda odpowiedzialna za wyswietlenie grafu nieskierowanego
void TestSolving::displayUndirectedGraph() {
    if (incidenceUndirectedMatrix != nullptr) {
        std::cout << std::endl << "Macierz incydencji dla grafu nieskierowanego:" << std::endl;
        incidenceUndirectedMatrix->display();
    }  else {
        std::cout << "Brak macierzy." << std::endl;
    }

    if (adjacencyUndirectedList != nullptr) {
        std::cout << std::endl << "Lista sasiedztwa dla grafu nieskierowanego:" << std::endl;
        adjacencyUndirectedList->display();
    } else {
        std::cout << "Brak listy" << std::endl;
    }
}

// Metoda odpowiedzialna za wyswietlenie grafu skierowanego
void TestSolving::displayDirectedGraph() {
    if (incidenceDirectedMatrix != nullptr) {
        std::cout << std::endl << "Macierz incydencji dla grafu skierowanego:" << std::endl;
        incidenceDirectedMatrix->display();
    }  else {
        std::cout << "Brak macierzy." << std::endl;
    }

    if (adjacencyDirectedList != nullptr) {
        std::cout << std::endl << "Lista sasiedztwa dla grafu skierowanego:" << std::endl;
        adjacencyDirectedList->display();
    } else {
        std::cout << "Brak listy." << std::endl;
    }
}

// Metoda odpowiedzialna za uruchomienie algorytmu Prima
void TestSolving::algorithmPrim() {
    if (incidenceUndirectedMatrix != nullptr) {
        cout << "Algorytm Prima dla macierzy incydencji:" << endl;
        Prim::runIncidenceMatrix(*incidenceUndirectedMatrix).display();
    } else {
        cout << "Brak macierzy" << endl;
    }

    if (adjacencyUndirectedList != nullptr) {
        cout << endl << "Algorytm Prima dla listy sasiedztwa:" << endl;
        Prim::runAdjacencyList(*adjacencyUndirectedList).display();
    } else {
        cout << "Brak listy" << endl;
    }
}

// Metoda odpowiedzialna za uruchomienie algorytmu Kruskala
void TestSolving::algorithmKruskal() {
    if (incidenceUndirectedMatrix != nullptr) {
        cout << "Algorytm Kruskala dla macierzy incydencji:" << endl;
        Kruskal::runIncidenceMatrix(*incidenceUndirectedMatrix).display();
    } else {
        cout << "Brak macierzy\n" << endl;
    }

    if (adjacencyUndirectedList != nullptr) {
        cout << endl << "Algorytm Kruskala dla listy sasiedztwa:" << endl;
        Kruskal::runAdjacencyList(*adjacencyUndirectedList).display();
    } else {
        cout << "Brak listy." << endl;
    }
}

// Metoda odpowiedzialna za uruchomienie algorytmu Dijkstry
void TestSolving::algorithmDijkstra() {
    int startingVertex, endingVertex;
    cout << "Krawedz startowa: ";
    cin >> startingVertex;
    cout << "Krawedz koncowa: ";
    cin >> endingVertex;

    if (incidenceDirectedMatrix != nullptr) {
        Array<int> result;
        cout << "Algorytm Dijkstry dla macierzy incydencji:" << endl;
        result = Dijkstra::runIncidenceMatrix(*incidenceDirectedMatrix, startingVertex, endingVertex);
        std::cout << std::endl << " Wynik algorytmu: " << std::endl;
        std::cout << " Sciezka: ";
        for (int i = 0; i < result.size() - 1; ++i) {
            std::cout << result[i] << " ";
        }
        std::cout << "\n Dystans: " << result[result.size() - 1] << std::endl << std::endl;
    } else {
        cout << "Brak macierzy" << endl;
    }

    if (adjacencyDirectedList != nullptr) {
        Array<int> result;
        cout << "Algorytm Dijkstry dla listy sasiedztwa:" << endl;
        result = Dijkstra::runAdjacencyList(*adjacencyDirectedList, startingVertex, endingVertex);
        std::cout << std::endl << " Wynik algorytmu: " << std::endl;
        std::cout << " Sciezka: ";
        for (int i = 0; i < result.size() - 1; ++i) {
            std::cout << result[i] << " ";
        }
        std::cout << "\n Dystans: " << result[result.size() - 1] << std::endl << std::endl;
    } else {
        cout << "Brak listy" << endl;
    }
}

// Metoda odpowiedzialna za uruchomienie algorytmu Bellmana-Forda
void TestSolving::algorithmFordBellman() {
    int startVertex, endVertex;
    cout << "Krawedz startowa: ";
    cin >> startVertex;
    cout << "Krawedz koncowa: ";
    cin >> endVertex;

    if (incidenceDirectedMatrix != nullptr) {
        Array<int> result;
        cout << "Algorytm Bellmana-Forda dla macierzy incydencji:" << endl;
        result = BellmanFord::runIncidenceMatrix(*incidenceDirectedMatrix, startVertex, endVertex);
        std::cout << std::endl << " Wynik algorytmu: " << std::endl;
        std::cout << " Sciezka: ";
        for (int i = 0; i < result.size() - 1; ++i) {
            std::cout << result[i] << " ";
        }
        std::cout << "\n Dystans: " << result[result.size() - 1] << std::endl << std::endl;
    } else {
        cout << "Brak macierzy" << endl;
    }

    if (adjacencyDirectedList != nullptr) {
        Array<int> result;
        cout << "Algorytm Bellmana-Forda dla listy sasiedztwa:" << endl;
        result = BellmanFord::runAdjacencyList(*adjacencyDirectedList, startVertex, endVertex);
        std::cout << std::endl << " Wynik algorytmu: " << std::endl;
        std::cout << " Sciezka: ";
        for (int i = 0; i < result.size() - 1; ++i) {
            std::cout << result[i] << " ";
        }
        std::cout << "\n Dystans: " << result[result.size() - 1] << std::endl << std::endl;
    } else {
        cout << "Brak listy" << endl;
    }
}
