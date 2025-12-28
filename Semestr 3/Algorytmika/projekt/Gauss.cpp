#include "Gauss.h"
#include <iostream>
#include <cmath>

#include "DaneWejsciowe.h"

using namespace std;

bool gaussPodstawowy(Macierz &macierz) {
    int n = macierz.size();

    for (int k = 0; k < n; k++) {
        if (fabs(macierz[k][k]) < 1e-12) {
            cout << "Blad: zerowy element na przekatnej (k = "
                    << k << ")\n";
            return false;
        }

        for (int i = k + 1; i < n; i++) {
            double wspolczynnik = macierz[i][k] / macierz[k][k];

            for (int j = k; j <= n; j++) {
                macierz[i][j] -= wspolczynnik * macierz[k][j];
            }

            cout << "\nPo wyzerowaniu A[" << i << "][" << k << "]\n";
            DaneWejsciowe::pokaz(macierz);
        }
    }

    // Wyliczanie niewiadomych
    vector<double> x(n);

    for (int i = n - 1; i >= 0; i--) {
        double suma = macierz[i][n];

        for (int j = i + 1; j < n; j++) {
            suma -= macierz[i][j] * x[j];
        }

        x[i] = suma / macierz[i][i];
    }

    cout << "\nRozwiazanie ukladu:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return true;
}

bool gaussKolumnowy(Macierz& macierz) {
    int n = macierz.size();

    for (int kolumna = 0; kolumna < n; kolumna++) {

        // 1. Szukanie najlepszego pivota w kolumnie
        int wierszMax = kolumna;
        double maxWartosc = fabs(macierz[kolumna][kolumna]);

        for (int i = kolumna + 1; i < n; i++) {
            if (fabs(macierz[i][kolumna]) > maxWartosc) {
                maxWartosc = fabs(macierz[i][kolumna]);
                wierszMax = i;
            }
        }

        // 2. Sprawdzenie czy 0 na przekatnej
        if (fabs(macierz[wierszMax][kolumna]) < 1e-12) {
            cout << "Blad: zerowy element w kolumnie "
                 << kolumna << endl;
            return false;
        }

        // 3. Zamiana wierszy (jeśli trzeba)
        if (wierszMax != kolumna) {
            swap(macierz[kolumna], macierz[wierszMax]);

            cout << "\nZamiana wierszy "
                 << kolumna << " <-> " << wierszMax << endl;
            DaneWejsciowe::pokaz(macierz);
        }

        // 4. Eliminacja (jak w metodzie podstawowej)
        for (int wiersz = kolumna + 1; wiersz < n; wiersz++) {

            double wspolczynnik =
                macierz[wiersz][kolumna] / macierz[kolumna][kolumna];

            for (int j = kolumna; j <= n; j++) {
                macierz[wiersz][j] -=
                    wspolczynnik * macierz[kolumna][j];
            }

            cout << "\nPo wyzerowaniu A[" << wiersz
                 << "][" << kolumna << "]\n";
            DaneWejsciowe::pokaz(macierz);
        }
    }

    // wyliczanie niewadomych
    vector<double> rozwiazania(n);

    for (int row = n - 1; row >= 0; row--) {
        double prawaStrona = macierz[row][n];

        for (int col = row + 1; col < n; col++) {
            prawaStrona -=
                macierz[row][col] * rozwiazania[col];
        }

        rozwiazania[row] =
            prawaStrona / macierz[row][row];
    }

    cout << "\nRozwiazanie ukladu:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = "
             << rozwiazania[i] << endl;
    }

    return true;
}
bool gaussWierszowy(Macierz& macierz) {
    int n = macierz.size();

    // wektor permutacji kolumn (kolejność zmiennych)
    vector<int> permutacja(n);
    for (int i = 0; i < n; i++) {
        permutacja[i] = i;
    }

    // ELIMINACJA W PRZÓD
    for (int wiersz = 0; wiersz < n; wiersz++) {

        // 1. Szukanie max elementu w WIERSZU
        int kolumnaMax = wiersz;
        double maxWartosc = fabs(macierz[wiersz][wiersz]);

        for (int j = wiersz + 1; j < n; j++) {
            if (fabs(macierz[wiersz][j]) > maxWartosc) {
                maxWartosc = fabs(macierz[wiersz][j]);
                kolumnaMax = j;
            }
        }

        // 2. Sprawdzenie osobliwości
        if (fabs(macierz[wiersz][kolumnaMax]) < 1e-12) {
            cout << "Blad: zerowy element w wierszu "
                 << wiersz << endl;
            return false;
        }

        // 3. Zamiana kolumn (jeśli trzeba)
        if (kolumnaMax != wiersz) {

            for (int i = 0; i < n; i++) {
                swap(macierz[i][wiersz],
                     macierz[i][kolumnaMax]);
            }

            swap(permutacja[wiersz],
                 permutacja[kolumnaMax]);

            cout << "\nZamiana kolumn "
                 << wiersz << " <-> " << kolumnaMax << endl;
            DaneWejsciowe::pokaz(macierz);
        }

        // 4. Eliminacja (jak zawsze)
        for (int i = wiersz + 1; i < n; i++) {

            double wspolczynnik =
                macierz[i][wiersz] / macierz[wiersz][wiersz];

            for (int j = wiersz; j <= n; j++) {
                macierz[i][j] -=
                    wspolczynnik * macierz[wiersz][j];
            }

            cout << "\nPo wyzerowaniu A[" << i
                 << "][" << wiersz << "]\n";
            DaneWejsciowe::pokaz(macierz);
        }
    }


    // PODSTAWIANIE WSTECZNE
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double prawaStrona = macierz[i][n];

        for (int j = i + 1; j < n; j++) {
            prawaStrona -= macierz[i][j] * x[j];
        }

        x[i] = prawaStrona / macierz[i][i];
    }

    // UWZGLĘDNIENIE PERMUTACJI
    vector<double> wynik(n);
    for (int i = 0; i < n; i++) {
        wynik[permutacja[i]] = x[i];
    }


    cout << "\nRozwiazanie ukladu:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = "
             << wynik[i] << endl;
    }

    return true;
}
