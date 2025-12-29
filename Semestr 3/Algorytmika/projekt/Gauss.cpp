#include "Gauss.h"
#include <iostream>
#include <cmath>

#include "DaneWejsciowe.h"
#include "GaussHelpers.h"

using namespace std;

bool gaussPodstawowy(Macierz &macierz) {
    int n = macierz.size();

    for (int k = 0; k < n; k++) {
        if (!poprawnyPivot(macierz[k][k])) {
            cout << "Blad: zerowy pivot w kolumnie "
                    << k + 1 << endl;
            return false;
        }

        eliminujKolumne(macierz, k);

        cout << "\nPo eliminacji kolumny "
                << k + 1 << " (metoda podstawowa):\n";
        DaneWejsciowe::pokaz(macierz);
    }

    auto x = podstawianieWsteczne(macierz);
    wypiszRozwiazanie(x);
    return true;
}


bool gaussKolumnowy(Macierz& A) {
    int n = A.size();

    for (int k = 0; k < n; k++) {

        int pivotRow = k;
        double maxVal = fabs(A[k][k]);

        for (int i = k + 1; i < n; i++) {
            if (fabs(A[i][k]) > maxVal) {
                maxVal = fabs(A[i][k]);
                pivotRow = i;
            }
        }

        if (!poprawnyPivot(A[pivotRow][k]))
            return false;

        if (pivotRow != k) {
            cout << "Zamiana wierszy: W"
                 << k + 1 << " <-> w" << pivotRow + 1 << endl;
            zamienWiersze(A, k, pivotRow);
            DaneWejsciowe::pokaz(A);
        }

        eliminujKolumne(A, k);

        cout << "Po eliminacji kolumny " << k + 1 << ":\n";
        DaneWejsciowe::pokaz(A);
    }

    wypiszRozwiazanie(podstawianieWsteczne(A));
    return true;
}



bool gaussWierszowy(Macierz& A) {
    int n = A.size();
    vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;

    for (int k = 0; k < n; k++) {

        int pivotCol = k;
        double maxVal = fabs(A[k][k]);

        for (int j = k + 1; j < n; j++) {
            if (fabs(A[k][j]) > maxVal) {
                maxVal = fabs(A[k][j]);
                pivotCol = j;
            }
        }

        if (!poprawnyPivot(A[k][pivotCol]))
            return false;

        if (pivotCol != k) {
            cout << "Zamiana kolumn: K"
                 << k + 1 << " <-> k" << pivotCol + 1 << endl;
            zamienKolumny(A, k, pivotCol);
            swap(perm[k], perm[pivotCol]);
            DaneWejsciowe::pokaz(A);
        }

        eliminujKolumne(A, k);

        cout << "Po eliminacji kolumny " << k + 1 << ":\n";
        DaneWejsciowe::pokaz(A);
    }

    vector<double> x = podstawianieWsteczne(A);
    vector<double> wynik(n);

    for (int i = 0; i < n; i++)
        wynik[perm[i]] = x[i];

    wypiszRozwiazanie(wynik);
    return true;
}



bool gaussPelny(Macierz& A) {
    int n = A.size();
    vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;

    for (int k = 0; k < n; k++) {

        int pivotRow = k, pivotCol = k;
        double maxVal = fabs(A[k][k]);

        for (int i = k; i < n; i++)
            for (int j = k; j < n; j++)
                if (fabs(A[i][j]) > maxVal) {
                    maxVal = fabs(A[i][j]);
                    pivotRow = i;
                    pivotCol = j;
                }

        if (!poprawnyPivot(A[pivotRow][pivotCol]))
            return false;

        if (pivotRow != k) {
            cout << "Zamiana wierszy: W"
                 << k + 1 << " <-> w" << pivotRow + 1 << endl;
            zamienWiersze(A, k, pivotRow);
            DaneWejsciowe::pokaz(A);
        }

        if (pivotCol != k) {
            cout << "Zamiana kolumn: K"
                 << k + 1 << " <-> k" << pivotCol + 1 << endl;
            zamienKolumny(A, k, pivotCol);
            swap(perm[k], perm[pivotCol]);
            DaneWejsciowe::pokaz(A);
        }

        eliminujKolumne(A, k);

        cout << "Po eliminacji kolumny " << k + 1 << ":\n";
        DaneWejsciowe::pokaz(A);
    }

    vector<double> x = podstawianieWsteczne(A);
    vector<double> wynik(n);

    for (int i = 0; i < n; i++)
        wynik[perm[i]] = x[i];

    wypiszRozwiazanie(wynik);
    return true;
}