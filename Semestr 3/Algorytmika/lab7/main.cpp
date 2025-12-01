#include <iostream>
#include <cmath>
#include <functional>
using namespace std;

double f1(double x) {
    double s = sin(x);
    return s * s + 2.0;
}

double f2(double x) {
    return exp(x) * 2 * pow(x, 3);
}

double trapezy(const function<double(double)> &f, double a, double b, int m) {
    double h = (b - a) / m;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < m; ++i) {
        double xi = a + i * h;
        sum += f(xi);
    }
    return sum * h;
}

double simpson(const function<double(double)> &f, double a, double b, int m) {
    if (m % 2 != 0) {
        cerr << "Simpson wymaga parzystej liczby podprzedzialow (m).\n";
        return NAN;
    }
    double h = (b - a) / m;
    double sum = f(a) + f(b);
    for (int i = 1; i < m; i++) {
        double xi = a + i * h;
        if (i % 2 == 1) {
            sum += 4.0 * f(xi);
        } else {
            sum += 2.0 * f(xi);
        }
    }
    return sum * (h / 3.0);
}

int main() {
    cout << "Wybierz calke (1 lub 2):\n";
    cout << "1) Calka (od 0 do 2pi) (sin^2 x + 2) dx\n";
    cout << "2) Calka (od 0 do 2) 2*x^3 * e^x dx\n";
    int wybor;
    cin >> wybor;

    cout << "Wybierz metode: T - trapezy, S - Simpson: ";
    char method;
    cin >> method;

    int n;
    cout << "Podaj liczbe podprzedzialow n (n > 1): ";
    cin >> n;

    double a =0.0;
    double b = 2.0;
    function<double(double)> f;
    if (wybor == 1) {
        b *= M_PI;
        f = f1;
    } else {
        f = f2;
    }

    double result;
    if (method == 'T' || method == 't') {
        result = trapezy(f, a, b, n);
        cout << "\nWynik:";
    } else {
        result = simpson(f, a, b, n);
        cout << "\nWynik:\n";
    }

    cout << "Przyblizona wartosc calki = " << result << "\n";

    return 0;
}
