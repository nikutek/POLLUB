#ifndef GAUSS_HELPERS_H
#define GAUSS_HELPERS_H

#include <vector>
#include "Gauss.h"

using namespace std;

bool poprawnyPivot(double wartosc);

void zamienWiersze(Macierz &A, int r1, int r2);

void zamienKolumny(Macierz &A, int c1, int c2);

void eliminujWiersz(
    Macierz &macierz,
    int wierszZrodlowy,
    int wierszDocelowy,
    int kolumnaStart
);

void eliminujKolumne(
    Macierz &macierz,
    int pivot
);

std::vector<double> podstawianieWsteczne(
    const Macierz &macierz
);

void wypiszRozwiazanie(
    const std::vector<double> &x
);

#endif
