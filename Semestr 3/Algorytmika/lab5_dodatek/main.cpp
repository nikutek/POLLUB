#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long fact(int n) {
    long long r = 1;
    for(int i = 2; i <= n; i++) r *= i;
    return r;
}

void wczytajDane(int &n,
                 vector<double> &xi,
                 vector<double> &fi,
                 vector<int> &k,
                 vector<vector<double>> &deriv)
{
    cout << "Podaj liczbe wezlow: ";
    cin >> n;

    xi.resize(n);
    fi.resize(n);
    k.resize(n);
    deriv.resize(n);

    for(int i = 0; i < n; i++) {
        cout << "\nWezel " << i+1 << " | Podaj x: ";
        cin >> xi[i];

        cout << "Podaj krotność wezla: ";
        cin >> k[i];

        cout << "Podaj f(x): ";
        cin >> fi[i];

        deriv[i].assign(k[i], 0.0);

        for(int r = 1; r < k[i]; r++) {
            cout << "Podaj pochodna rzedu " << r << ": ";
            cin >> deriv[i][r];
        }
    }
}

void stworzTabliceWezlow(const vector<double> &xi,
                          const vector<int> &k,
                          vector<double> &X,
                          vector<int> &orig)
{
    int total = 0;
    for(int t : k) total += t;

    X.resize(total);
    orig.resize(total);

    int idx = 0;
    for(int i = 0; i < xi.size(); i++) {
        for(int j = 0; j < k[i]; j++) {
            X[idx] = xi[i];
            orig[idx] = i;
            idx++;
        }
    }
}

void interujTabliceIlorazow(const vector<double> &X,
                    const vector<int> &orig,
                    const vector<double> &fi,
                    const vector<int> &k,
                    const vector<vector<double>> &deriv,
                    vector<double> &Q)
{
    int m = X.size();
    Q.assign(m*m, 0.0);

    // kolumna zerowa: f
    for(int i = 0; i < m; i++)
        Q[i*m + 0] = fi[ orig[i] ];

    // kolumna 1: pochodne / ilorazy
    for(int i = 1; i < m; i++) {
        if (fabs(X[i] - X[i-1]) < 1e-15) {
            int oi = orig[i];
            Q[i*m + 1] = deriv[oi][1]; //pochodna
        } else {
            //iloraz różnicowy
            Q[i*m + 1] = (Q[i*m + 0] - Q[(i-1)*m + 0]) / (X[i] - X[i-1]);
        }
    }

    // dalsze kolumny
    for(int col = 2; col < m; col++) {
        for(int row = col; row < m; row++) {

            if (fabs(X[row] - X[row-col]) < 1e-15) {
                int oi = orig[row];
                if (deriv[oi].size() > col)
                    Q[row*m + col] = deriv[oi][col] / fact(col);
                else
                    Q[row*m + col] = 0.0;
            } else {
                Q[row*m + col] =
                    (Q[row*m + (col-1)] - Q[(row-1)*m + (col-1)]) /
                    (X[row] - X[row-col]);
            }
        }
    }
}

vector<double> mnozenieWielomianu(const vector<double> &a, double b0) {
    int n = a.size();
    vector<double> r(n, 0.0);

    for(int i = n-1; i >= 1; i--)
        r[i] += a[i-1];

    for(int i = 0; i < n; i++)
        r[i] -= a[i] * b0;

    return r;
}

void wypiszWielomian(const vector<double> &X,
                            const vector<double> &Q)
{
    int n = X.size();
    vector<double> poly(n, 0.0);
    vector<double> term(n, 0.0);
    term[0] = 1.0;
    poly[0] = Q[0];

    for(int i = 1; i < n; i++) {
        term = mnozenieWielomianu(term, X[i-1]);
        double a = Q[i*n + i];
        for(int j = 0; j < n; j++)
            poly[j] += a * term[j];
    }

    cout << "\nW(x) = ";
    bool first = true;

    for(int i = poly.size() - 1; i >= 0; i--) {
        if (fabs(poly[i]) < 1e-12) continue;

        if (!first) cout << (poly[i] >= 0 ? " + " : " - ");
        else if (poly[i] < 0) cout << "-";

        first = false;

        double c = fabs(poly[i]);

        if (i == 0) cout << c;
        else if (i == 1) cout << c << "x";
        else cout << c << "x^" << i;
    }
    cout << "\n";
}


int main() {
    int n;
    vector<double> xi, fi;
    vector<int> k;
    vector<vector<double>> deriv;

    wczytajDane(n, xi, fi, k, deriv);

    vector<double> X;
    vector<int> orig;
    stworzTabliceWezlow(xi, k, X, orig);

    vector<double> Q;
    interujTabliceIlorazow(X, orig, fi, k, deriv, Q);

    wypiszWielomian(X, Q);

    return 0;
}
