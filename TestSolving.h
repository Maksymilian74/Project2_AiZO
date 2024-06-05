#ifndef PROJEKT2_AIZO_TESTSOLVING_H
#define PROJEKT2_AIZO_TESTSOLVING_H

#include <chrono>
#include <string>

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

private:
    std::chrono::high_resolution_clock::time_point start; // Zmienna przechowujaca początek pomiaru czasu
    std::chrono::high_resolution_clock::time_point stop; // Zmienna przechowujaca koniec pomiaru czasu
    double time; // Zmienna przechowujaca czas sortowania
};

#endif
