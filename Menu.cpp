#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::runMainMenu() { // Implementacja glownego menu
    int number;
    int test;
    int simulation;
    do {
        number = displayMainMenu(); // Wyswietlenie glownego menu
        switch (number) {
            case 1:
                cout << "-------------------------------------------\n";
                cout << "Tryb pracy testowej\n";
                //tworzenie obiektu podmenu
                do {
                    test = displayTestingMenu(); // Wyswieltenie menu dla trybu testowania
                    switch (test) {
                        case 1:
                            cout << "-------------------------------------------\n";
                            cout << "Wczytanie danych z pliku\n";
                            cout << "Podaj nazwe pliku z rozszerzeniem\n";
                            break;
                        case 2:
                            cout << "-------------------------------------------\n";
                            cout << "Wygenerowanie grafu losowo\n";
                            break;
                        case 3:
                            cout << "-------------------------------------------\n";
                            cout << "Wyswietlenie grafu\n";
                            break;
                        case 4:
                            cout << "-------------------------------------------\n";
                            cout << "Algorytm MST\n";
                            break;
                        case 5:
                            cout << "Algorytm najkrotszej sciezki\n";
                            break;
                        case 6:
                            cout << "-------------------------------------------\n";
                            cout << "Algorytm maksymalnego przeplywu\n";
                            break;
                        case 7:
                            cout << "-------------------------------------------\n";
                            cout << "Wyjscie do wyboru trybu pracy  \n";
                            break;
                        default:
                            cout << "-------------------------------------------\n";
                            cout << "Bledny numer, podaj prawidlowa wartosc\n";
                            break;
                    }
                } while(test != 7);
                break;
            case 2:
                cout << "-------------------------------------------\n";
                cout << "Tryb pracy badawczej\n";
                //tworzenie obiektu podmenu
                do {
                    simulation = displaySimulationMenu(); // Wyswietlenie menu dla trybu badawczego
                    switch (simulation) {
                        case 1:
                            cout << "-------------------------------------------\n";
                            cout << "Wybor algorytmu\n";
                            break;
                        case 2:
                            cout << "-------------------------------------------\n";
                            cout << "Wyjscie do wyboru trybu pracy  \n";
                            break;
                        default:
                            cout << "-------------------------------------------\n";
                            cout << "Bledny numer, podaj prawidlowa wartosc\n";
                            break;
                    }
                } while(simulation != 2);
                break;
            case 3:
                cout << "-------------------------------------------\n";
                cout << "Zakonczenie dzialania programu\n";
                break;
            default:
                cout << "-------------------------------------------\n";
                cout << "Bledny numer, podaj prawidlowa wartosc\n";
                break;
        }
    } while (number != 3);


}

int Menu::displayMainMenu() { // Implementacja wyswietlania glownego menu
    int task;
    cout << "---------------------------\n";
    cout << "     --- Main Menu ---     \n";
    cout << "1. Tryb pracy testowej     \n";
    cout << "2. Tryb pracy badawczej    \n";
    cout << "3. Wyjscie                 \n";
    cout << "Wpisz numer zadania:";
    cin >> task;
    return task;
}

int Menu::displayTestingMenu() { // Implementacja wyswietlania menu dla trybu testowego
    int task;
    cout << "------------------------------------------------\n";
    cout << "            --- Testing Menu ---                \n";
    cout << "1. Wczytanie danych z pliku                     \n";
    cout << "2. Wygenerowanie grafu losowo                   \n";
    cout << "3. Wyswietlenie grafu                           \n";
    cout << "4. Uruchom algorytm MST                         \n";
    cout << "5. Uruchom algorytm najkrotszej sciezki         \n";
    cout << "6. Uruchom algorytm maksymalnego przeplywu      \n";
    cout << "7. Wyjscie do wyboru trybu pracy                \n";
    cout << "Wpisz numer zadania:";
    cin >> task;
    return task;
}

int Menu::displaySimulationMenu() { // Implementacja wyswietlania menu dla trybu badawczego
    int task;
    cout << "---------------------------------- \n";
    cout << "      --- Simulation Menu ---      \n";
    cout << "1. Wybor algorytmu                 \n";
    cout << "2. Wyjscie do wyboru trybu pracy   \n";
    cout << "Wpisz numer zadania:";
    cin >> task;
    return task;
}