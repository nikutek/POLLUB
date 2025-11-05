#include <iostream>
#include <vector>

using namespace std;

vector<double> newton(vector<double> xi, vector<double> fi) {
    int n = fi.size();
    vector<double> ir(fi);

    for (int i = 0; i <= n; i++) {
        ir.push_back(fi[i]);
    }

    for (int k = 1; k < n; k++) {
        int i = n;
        for (int i = n - 1; i >= k; i--) {
            ir[i] = (ir[i] - ir[i - 1]) / (xi[i] - xi[i - k]);
            i--;
        }
        k++;
    }
    return ir;
}

void policzWPunkcie(vector<double> ir, double p, int n, vector<double> xi) {
    double wynik = ir[0];
    double iloczyn = 1.0;

    for (int i = 1; i < n; i++) {
        iloczyn *= (p - xi[i - 1]);
        wynik += ir[i] * iloczyn;
    }

    cout << "Przyblizona wartosc funkcji w punkcie p = " << p << " wynosi: " << wynik << endl;
}


int main() {
    int n, iloscWezlow;
    cout << "Podaj liczbe wezlow: ";
    cin >> iloscWezlow;
    n = iloscWezlow - 1;


    vector<double> xi(iloscWezlow);
    vector<double> fi(iloscWezlow);

    for (int i = 0; i < iloscWezlow; i++) {
        cout << "Wezel " << i + 1 << " | Podaj x: ";
        cin >> xi[i];
        cout << "Wezel " << i + 1 << " | Podaj f(x): ";
        cin >> fi[i];
    }

    for (int i = 1; i < iloscWezlow; i++) {
        if (xi[i] <= xi[i - 1]) {
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

    vector<double> ir = newton(xi, fi);

    policzWPunkcie(ir, p, n, xi);

    return 0;
}
