#ifndef PROJEKT2_AIZO_MENU_H
#define PROJEKT2_AIZO_MENU_H

#include <iostream>

using namespace std;

class Menu {
public:
    void runMainMenu();

private:
    // Metoda wyswietlajaca menu glowne
    int displayMainMenu();

    // Metoda wyswietlajaca menu dla trybu testowego
    int displayTestingMenu();

    // Metoda wyswietlajaca menu dla trybu badawczego
    int displaySimulationMenu();
};


#endif
