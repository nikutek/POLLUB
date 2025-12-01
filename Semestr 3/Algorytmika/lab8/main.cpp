#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const double PI = 3.14159265358979323846;

double gaussChebyshev() {
    int n = 3;
    int nodes = n + 1;
    double sum = 0.0;
    double H = PI / nodes;

    for (int j = 0; j < nodes; ++j) {
        double x_j = cos((2.0 * j + 1.0) * PI / (2.0 * nodes));
        double f = (x_j * x_j);
        sum += H * f;
    }
    return sum;
}

double gaussLegendre() {
    vector<double> pierwiastki = {-0.906180, -0.538469, 0.0, 0.538469, 0.906180};
    vector<double> h = {0.236927, 0.478629, 0.568889, 0.478629, 0.236927};

    double sum = 0.0;
    for (size_t i = 0; i < pierwiastki.size(); ++i) {
        double x = pierwiastki[i];
        double f = 1.0 / sqrt(1.0 + x * x);
        sum += h[i] * f;
    }
    return sum;
}

double gaussLaguerre() {
    vector<double> pierwiastki = {0.322548, 1.745761, 4.536620, 9.395071};
    vector<double> h = {0.603154, 0.357419, 0.038888, 0.000539};

    double sum = 0.0;
    for (size_t i = 0; i < pierwiastki.size(); ++i) {
        double x = pierwiastki[i];
        double f = exp(-x) * sin(x) / x;
        sum += h[i] * f;
    }
    return sum;
}

double gaussHermite() {
    vector<double> pierwiastki = {-2.020183, -0.958572, 0.0, 0.958572, 2.020183};
    vector<double> h = {0.019953, 0.393619, 0.945309, 0.393619, 0.019953};

    double sum = 0.0;
    for (size_t i = 0; i < pierwiastki.size(); ++i) {
        double x = pierwiastki[i];
        double f = cos(x);
        sum += h[i] * f;
    }
    return sum;
}

int main() {

    double result_a = gaussChebyshev();
    cout << "Gauss-Chebyshev (n=3)= " << result_a << endl;

    double result_b = gaussLegendre();
    cout << "Gauss-Legendre (n=4)= " << result_b << endl;

    double result_c = gaussLaguerre();
    cout << "Gauss-Laguerre (n=3)= " << result_c << endl;

    double result_d = gaussHermite();
    cout << "Gauss-Hermite (n=4)= " << result_d << endl;

    return 0;
}