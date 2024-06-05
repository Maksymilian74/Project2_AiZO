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
}

// Destruktor
TestSolving:: ~TestSolving() {

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
void TestSolving::generateRandomGraph(int size, int fillingMethod) {

}

// Metoda odpowiedzialna za wyswietlenie grafu
void TestSolving::displayGraph() {

}


