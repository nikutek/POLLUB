#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;

double suma(const vector<double> &a) {
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i) sum += a[i];
    return sum;
}

double iloczynSkalarny(const vector<double> &a, const vector<double> &b) {
    if (a.size() != b.size()) {
        throw invalid_argument("iloczynSkalarny: wektory musza byc tego samego rozmiaru");
    }
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i) sum += a[i] * b[i];
    return sum;
}

// Oblicza a i b we wzorze g(x) = a*x + b (metoda najmniejszych kwadratów)
void aproksymacjaLiniowa(const vector<double> &x, const vector<double> &f, int n) {
    if (n <= 1) {
        cout << "Za malo punktow do aproksymacji.\n";
        return;
    }

    double Sx  = suma(x);
    double Sf  = suma(f);
    double Sx2 = iloczynSkalarny(x, x); // suma x_i^2
    double Sxf = iloczynSkalarny(x, f);

    double denom = n * Sx2 - Sx * Sx;
    const double EPS = 1e-15;
    if (fabs(denom) < EPS) {
        cout << "Blad: mianownik bliski zeru (punkty x sa zbyt skorelowane).\n";
        return;
    }

    double a = (n * Sxf - Sx * Sf) / denom;
    double b = (Sf - a * Sx) / n;

    cout << "\nWynik aproksymacji liniowej g(x) = a*x + b:\n";
    cout << "y = " << a << "x" << (b>0 ? " + " : "") << b << "\n";
}


void aproksymacjaHiperboliczna(const vector<double> &x, const vector<double> &f, int n) {
    if (n <= 1) {
        cout << "Za malo punktow do aproksymacji.\n";
        return;
    }
    vector<double> u(n);
    for (int i = 0; i < n; ++i) {
        u[i] = 1.0 / x[i];
    }

    double Su  = suma(u);
    double Sf  = suma(f);
    double Su2 = iloczynSkalarny(u, u);
    double Suf = iloczynSkalarny(u, f);

    double wyznacznikMacierzy = n * Su2 - Su * Su;
    const double EPS = 1e-15;
    if (fabs(wyznacznikMacierzy) < EPS) {
        cout << "Blad: mianownik zero.\n";
        return;
    }

    double a = (n * Suf - Su * Sf) / wyznacznikMacierzy;
    double b = (Sf - a * Su) / n;

    cout << "\nWynik aproksymacji hiperbolicznej g(x) = a/x + b:\n";
    cout << "y = " << a << "x" << (b>0 ? " + " : "") << b << "\n";

}


int main() {
    int n;
    cout << "Podaj liczbe wezlow: ";
    cin >> n;

    vector<double> x(n), f(n);

    for (int i = 0; i < n; i++) {
        cout << "Wezel " << i + 1 << " | Podaj x: ";
        cin >> x[i];

        cout << "Podaj f(x): ";
        cin >> f[i];
    }

    cout << "\nWybierz funkcje aproksymujaca:\n";
    cout << "1) g(x) = a*x + b\n";
    cout << "2) g(x) = a/x + b\n";
    cout << "Opcja: ";

    int wybor;
    cin >> wybor;

    if (wybor == 1)
        aproksymacjaLiniowa(x, f, n);
    else if (wybor == 2)
        aproksymacjaHiperboliczna(x, f, n);
    else
        cout << "Bledna opcja!\n";

    return 0;
}




