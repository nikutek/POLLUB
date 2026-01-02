#include "DaneWejsciowe.h"

#include <iostream>

using namespace std;

static const vector<vector<Macierz>> DANE = {

    // METODA 1
    {
            {   // zestaw 1
                { 2,  1, -1,  8},
                {-3, -1,  2, -11},
                {-2,  1,  2, -3}
            },
            {   // zestaw 2
                { 0,  2,  9, 7},
                { 1, -1,  2, 3},
                { 3,  2, -1, 5}
            }
    },

    // METODA 2
    {
            {
                {0.0001, 1, 1, 2},
                {1,      2, 3, 6},
                {2,      1, 1, 4}
            },
            {
                {1e-20, 1, 1, 2},
                {1,     1, 2, 4},
                {2,     2, 3, 6}
            }
    },

    // METODA 3
    {
            {
                { 1,  2,  3, 6},
                { 4,  5,  6, 15},
                { 7,  8, 10, 25}
            },
            {
                { 1, 1000, 1, 1002},
                { 2, 1,    1, 4},
                { 3, 1,    1, 5}
            }
    },

    // METODA 4
    {
            {
                { 1, 2, 3, 6},
                { 4, 5, 6, 15},
                { 7, 8, 10, 25}
            },
            {
                { 0, 2, 3, 5},
                { 1, 0, 4, 6},
                { 2, 1, 0, 3}
            }
    }
};

const Macierz& DaneWejsciowe::pobierz(int metoda, int zestaw) {
    return DANE.at(metoda - 1).at(zestaw - 1);
}


void DaneWejsciowe::pokaz(int metoda, int zestaw) {
    const Macierz& macierz = pobierz(metoda, zestaw);

    for (size_t i = 0; i < macierz.size(); i++) {
        for (size_t j = 0; j < macierz[i].size() - 1; j++) {
            cout << macierz[i][j] << " ";
        }
        cout << "| " << macierz[i].back() << endl;
    }
}

void DaneWejsciowe::pokaz(const Macierz& macierz) {
    cout << "-------------------------\n";
    for (const auto& wiersz : macierz) {
        for (size_t j = 0; j < wiersz.size() - 1; j++) {
            cout << wiersz[j] << " ";
        }
        cout << "| " << wiersz.back() << endl;
    }
    cout << "-------------------------\n";
}



