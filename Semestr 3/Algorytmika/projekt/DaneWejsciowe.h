#include "Gauss.h"

class DaneWejsciowe {
public:
    static const Macierz& pobierz(int metoda, int zestaw);

    static void pokaz(int metoda, int zestaw);

    static void pokaz(const Macierz& macierz);

    static Macierz wczytajMacierzOdUzytkownika();
};
