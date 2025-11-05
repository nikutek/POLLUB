#include <iostream>
#include <vector>
using namespace std;

double neville(vector<double> xi, vector<double> fi, double p) {
    int n = xi.size();
    vector<vector<double>> P;
    for (int i=0; i<=n; i++) {
        P.push_back(vector<double>(n-i));
    }

    for (int i = 0; i < n; i++) {
        P[i][0] = fi[i];
    }

    for (int k = 1; k < n; k++) {
        for (int j = 0; j < n - k; j++) {
            P[j][k] = ((p - xi[j]) * P[j + 1][k - 1] - (p - xi[j + k]) * P[j][k - 1]) / (xi[j + k] - xi[j]);
        }
    }

    return P[0][n - 1];
}

int main() {
    int iloscWezlow;
    cout << "Podaj liczbe wezlow: ";
    cin >> iloscWezlow;

    vector<double> xi(iloscWezlow);
    vector<double> fi(iloscWezlow);

    for (int i = 0; i < iloscWezlow; i++) {
        cout << "Wezel " << i + 1 << " | Podaj x: ";
        cin >> xi[i];
        cout << "Wezel " << i + 1 << " | Podaj f(x): ";
        cin >> fi[i];
    }

    double p;
    cout << "Podaj punkt p: ";
    cin >> p;

    double wynik = neville(xi, fi, p);
    cout << "Przyblizona wartosc funkcji w punkcie p = " << p << " wynosi: " << wynik << endl;

    return 0;
}
