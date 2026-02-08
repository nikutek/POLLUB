#include <cmath>
#include <iostream>

using namespace std;

float funkcja(float x) {
    return pow(x, 3) - 71;
}

float pochodnaf(float x) {
    return 3 * pow(x, 2);
}

float bisekcja(float a, float b, float eps) {
    float s;
    int k =0;
    while (abs(b - a) > eps) {
        s = (a + b) / 2;
        if (funkcja(a) * funkcja(s) < 0) {
            b = s;
        } else {
            a = s;
        }
        k++;
    }
    cout << "miejsce zerowe (bisekcja): " << s << endl;
    cout << "Ilosc iteracji: " << k << endl;
    return s;
}

float newton(float x0, float eps) {
    float x_next = x0 - (funkcja(x0) / pochodnaf(x0));
    int k=0;
    while (abs(x_next - x0) > eps) {
        x0 = x_next;
        x_next = x0 - (funkcja(x0) / pochodnaf(x0));
        k++;
    }
    cout << "miejsce zerowe (Newton): " << x_next << endl;
    cout << "Ilosc iteracji: " << k << endl;
    return x_next;
}

int main() {
    float eps = 0.01;

    float x1 = bisekcja(4, 5, eps);
    cout << "f(x) = " << funkcja(x1) << endl;

    float x2 =  newton(1, eps);
    cout << "f(x) = " << funkcja(x2) << endl;
    return 0;
}