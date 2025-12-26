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
