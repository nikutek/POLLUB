#include <iostream>
#include "DaneWejsciowe.h"
#include "Gauss.h"

using namespace std;

Macierz wczytajMacierzOdUzytkownika() {
    int n;
    cout << "\nPodaj liczbe niewiadomych (n): ";
    cin >> n;

    Macierz macierz(n, vector<double>(n + 1));

    cout << "\nPodaj elementy macierzy rozszerzonej (wierszami):\n";


    for (int i = 0; i < n; i++) {
        cout << "Wiersz " << i + 1 << ": ";
        for (int j = 0; j <= n; j++) {
            cin >> macierz[i][j];
        }
    }

    cout << "\nWprowadzona macierz:\n";
    DaneWejsciowe::pokaz(macierz);

    return macierz;
}

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

    int wyborDanych = 0;

    cout << "\nWybierz zrodlo danych:\n";
    cout << "1. Gotowe zestawy\n";
    cout << "2. Wlasne dane\n";
    cout << "Twoj wybor: ";
    cin >> wyborDanych;

    Macierz dane;

    if (wyborDanych == 1) {

        cout << "\nDostepne zestawy danych dla metody "
             << metoda << ":\n\n";

        cout << "ZESTAW 1:\n";
        daneWejsciowe.pokaz(metoda, 1);

        cout << "\nZESTAW 2:\n";
        daneWejsciowe.pokaz(metoda, 2);

        while (true) {
            cout << "\nWybierz zestaw (1 lub 2): ";
            cin >> zestaw;

            if (zestaw == 1 || zestaw == 2) break;
            cout << "Niepoprawny zestaw. Sprobuj ponownie.\n";
        }

        dane = daneWejsciowe.pobierz(metoda, zestaw);

    }
    else if (wyborDanych == 2) {

        dane = wczytajMacierzOdUzytkownika();

    }
    else {
        cout << "Niepoprawny wybor. Koniec programu.\n";
        return 0;
    }

    switch (metoda) {
        case 1:
            gaussPodstawowy(dane);
            return 0;
        case 2:
            cout << "Metoda 2";
            gaussKolumnowy(dane);
            return 0;
        case 3:
            cout << "Metoda 3";
            gaussWierszowy(dane);
            return 0;
        case 4:
            cout << "Metoda 4";
            gaussPelny(dane);
            return 0;
    }
    daneWejsciowe.pokaz(metoda, zestaw);
    return 0;
}
