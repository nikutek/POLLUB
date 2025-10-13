#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

vector<int> policzWyniki(const vector<int>& wspolczynniki, int punkt) {
    int stopien = wspolczynniki.size() - 1;
    vector<int> wyniki;
    wyniki.push_back(wspolczynniki[0]);

    for (int i = 1; i <= stopien; i++) {
        int ostatni = wyniki[i - 1];
        int wynik = wspolczynniki[i] + ostatni * punkt;
        wyniki.push_back(wynik);
    }
    return wyniki;
}

int main() {
    int punkt = 2;
    int stopien = 4;

    vector<int> wspolczynniki = {-3, 0, 1, -2, 4};

    vector<int> pochodne;
    vector<int> wyniki = policzWyniki(wspolczynniki, punkt);

    while (wyniki.size() > 1) {
        pochodne.push_back(wyniki.back());
        wyniki.pop_back();
        wyniki = policzWyniki(wyniki, punkt);
    }

    pochodne.push_back(wyniki[0]);
    wyniki.pop_back();

    for (int p : pochodne) {
        wyniki.push_back(p);
    }

    for (int i = 0; i <= stopien; i++) {
        cout << "w<" << i << ">(2)=" << wyniki[i] * factorial(i) << endl;
    }

    return 0;
}
