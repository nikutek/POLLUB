#ifndef DANE_WEJSCIOWE_H
#define DANE_WEJSCIOWE_H

#include <vector>

using Macierz = std::vector<std::vector<double>>;

class DaneWejsciowe {
public:
    static const Macierz& pobierz(int metoda, int zestaw);
    static void pokaz(int metoda, int zestaw);
};

#endif
