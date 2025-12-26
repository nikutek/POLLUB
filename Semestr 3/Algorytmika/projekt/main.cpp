#include <iostream>
#include "DaneWejsciowe.h"
#include "Gauss.h"

using namespace std;

int main() {

    int metoda = 0;
    int zestaw = 0;
    DaneWejsciowe daneWejsciowe;

    cout << "Rozwiazywanie ukladow rownan metoda eliminacji Gaussa\n\n";

    while (true) {
        cout << "Wybierz metode:\n";
        cout << "1. Metoda podstawowa\n";
        cout << "2. Wybor elementu maksymalnego w kolumnie\n";
        cout << "3. Wybor elementu maksymalnego w wierszu\n";
        cout << "4. Pelny wybor elementu maksymalnego\n";
        cout << "Twoj wybor: ";

        cin >> metoda;

        if (metoda >= 1 && metoda <= 4) {
            break;
        }

        cout << "Niepoprawna metoda. Sprobuj ponownie.\n\n";
    }

    cout << "\nDostepne zestawy danych dla metody " << metoda << ":\n\n";

    cout << "ZESTAW 1:\n";
    daneWejsciowe.pokaz(metoda, 1);

    cout << "\nZESTAW 2:\n";
    daneWejsciowe.pokaz(metoda, 2);

    while (true) {
        cout << "\nWybierz zestaw (1 lub 2): ";
        cin >> zestaw;

        if (zestaw == 1 || zestaw == 2) {
            break;
        }

        cout << "Niepoprawny zestaw. Sprobuj ponownie.\n";
    }

    Macierz dane = daneWejsciowe.pobierz(metoda,zestaw);

    switch (metoda) {
        case 1:
            gaussPodstawowy(dane);
            return 0;
        case 2:
            cout << "Metoda 2";
            return 0;
        case 3:
            cout << "Metoda 3";
            return 0;
        case 4:
            cout << "Metoda 4";
            return 0;




    }
    daneWejsciowe.pokaz(metoda, zestaw);



    return 0;
}
