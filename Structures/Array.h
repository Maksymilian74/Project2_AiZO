/*
 * Klasa Array odpowiedzialna jest za
 * implementacje tablicy
 *
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array {
public:

    Array() = default;  // Konstruktor domyslny
    explicit Array(int size);  // Konstruktor z rozmiarem
    Array(const Array& other);  // Konstruktor kopiujacy

    Array& operator=(const Array& other);      // Operator przypisania

    T& operator[](int index) const;  // Operator dostepu do elementu (const)
    T& operator[](int index);       // Operator dostepu do elementu

    void pushBack(const T& value);  // Metoda dodajaca element na koniec
    void popBack();                 // Metoda usuwajaca element z konca
    void resize(int newSize);       // Zmiana rozmiaru tablicy

    int size() const;       // Metoda zwracajaca rozmiar tablicy

private:
    T* data;           // Wskaznik na dane tablicy
    size_t sizeOfTab;  // Rozmiar tablicy
};


#endif
