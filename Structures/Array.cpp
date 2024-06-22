#include "Array.h"

// Konstruktor
template <typename T>
Array<T>::Array(int size) {
    data = new T[size];
    sizeOfTab = size;
}

// Konstruktor kopiujacy
template <typename T>
Array<T>::Array(const Array& other) {
    data = new T[other.sizeOfTab];
    sizeOfTab = other.sizeOfTab;
    for (int i = 0; i < sizeOfTab; i++) {
        data[i] = other.data[i];
    }
}

// Operator przypisania
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this == &other) {
        return *this;
    }

    // Alokacja pamieci
    T* newData = new T[other.sizeOfTab];
    for (int i = 0; i < other.sizeOfTab; i++) {
        newData[i] = other.data[i];
    }

    // Podmiana danych na nowe
    data = newData;
    sizeOfTab = other.sizeOfTab;

    return *this;
}

// Operator dostepu do elementu (const)
template <typename T>
T& Array<T>::operator[](int index) const {
    return data[index];
}

// Operator dostepu do elementu
template <typename T>
T& Array<T>::operator[](int index) {
    return data[index];
}

// Zwraca rozmiar tablicy
template <typename T>
int Array<T>::size() const {
    return sizeOfTab;
}

// Zmiana rozmiaru tablicy
template <typename T>
void Array<T>::resize(int newSize) {
    if (newSize < 0) {
        std::cerr << "Blad: Niepoprawna wartosc rozmiaru." << std::endl;
        return;
    }
    delete[] data;
    data = new T[newSize];
    sizeOfTab = newSize;
}

// Dodanie elementu na koniec
template <typename T>
void Array<T>::pushBack(const T& value) {
    T* newData = new T[sizeOfTab + 1];
    for (int i = 0; i < sizeOfTab; i++) {
        newData[i] = data[i];
    }
    newData[sizeOfTab] = value;
    delete[] data;
    data = newData;
    sizeOfTab++;
}

// Usuniecie elementu z konca
template <typename T>
void Array<T>::popBack() {
    if (sizeOfTab > 0) {
        sizeOfTab--;
        T* newData = new T[sizeOfTab];
        for (int i = 0; i < sizeOfTab; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
}