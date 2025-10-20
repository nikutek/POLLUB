#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double Lagrange(const vector<double>& x, const vector<double>& f, double p) {
    int n = x.size();
    double wynik = 0.0;

    for (int i = 0; i < n; i++) {
        double li = 1.0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                li *= (p - x[j]) / (x[i] - x[j]);
            }
        }
        wynik += f[i] * li;
    }
    return wynik;
}

int main() {
    int n;
    cout << "Podaj liczbe wezlow: ";
    cin >> n;

    vector<double> xi(n);
    vector<double> fi(n);

    for (int i = 0; i < n; i++) {
        cout << "Wezel " << i+1 << " | Podaj x: ";
        cin >> xi[i];
        cout << "Wezel " << i+1 << " | Podaj f(x): ";
        cin >> fi[i];
    }

    for (int i = 1; i < n; i++) {
        if (xi[i] <= xi[i-1]) {
            cout << "Wezly musza byc rosnace i rozne!" << endl;
            return 1;
        }
    }

    double p;
    cout << "Podaj punkt p: ";
    cin >> p;

    if (p < xi.front() || p > xi.back()) {
        cout << "Blad: punkt poza zakresem [" << xi.front() << ", " << xi.back() << "]" << endl;
        return 1;
    }


    double wynik = Lagrange(xi, fi, p);
    cout << "Przyblizona wartosc funkcji w " << p << " wynosi: " << wynik << endl;

    return 0;
}
