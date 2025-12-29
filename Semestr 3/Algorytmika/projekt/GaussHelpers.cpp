#include "GaussHelpers.h"
#include <iostream>
#include <cmath>

#include "DaneWejsciowe.h"

using namespace std;

bool poprawnyPivot(double wartosc) {
    return fabs(wartosc) >= 1e-12;
}

void zamienWiersze(Macierz& A, int r1, int r2) {
    swap(A[r1], A[r2]);
}

void zamienKolumny(Macierz& A, int c1, int c2) {
    for (auto& wiersz : A) {
        swap(wiersz[c1], wiersz[c2]);
    }
}

void eliminujWiersz(
    Macierz &macierz,
    int wierszZrodlowy,
    int wierszDocelowy,
    int kolumnaStart
) {
    int n = macierz.size();
    double wsp =
            macierz[wierszDocelowy][kolumnaStart] /
            macierz[wierszZrodlowy][kolumnaStart];

    for (int j = kolumnaStart; j <= n; j++) {
        macierz[wierszDocelowy][j] -=
                wsp * macierz[wierszZrodlowy][j];
    }
}

void eliminujKolumne(
    Macierz &macierz,
    int pivot
) {
    int n = macierz.size();

    for (int i = pivot + 1; i < n; i++) {
        eliminujWiersz(macierz, pivot, i, pivot);
    }
}

vector<double> podstawianieWsteczne(
    const Macierz &macierz
) {
    int n = macierz.size();
    vector<double> x(n);

    for (int i = n - 1; i >= 0; i--) {
        double suma = macierz[i][n];

        for (int j = i + 1; j < n; j++) {
            suma -= macierz[i][j] * x[j];
        }

        x[i] = suma / macierz[i][i];
    }

    return x;
}

void wypiszRozwiazanie(
    const vector<double> &x
) {
    cout << "\nRozwiazanie ukladu:\n";
    for (size_t i = 0; i < x.size(); i++) {
        cout << "x" << i + 1 << " = "
                << x[i] << endl;
    }
}
