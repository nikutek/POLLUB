#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

float lss(vector<vector<float>> &A, vector<vector<float>> &L, int s) {
    float suma = 0;
    for (int j = 0; j < s; j++) {
        suma += L[s][j] * L[s][j];
    }
    return sqrt(A[s][s] - suma);
}

float lis(vector<vector<float>> &A, vector<vector<float>> &L, int s, int i) {
    float suma = 0;
    for (int j = 0; j < s; j++) {
        suma += L[i][j] * L[s][j];
    }
    return (A[i][s] - suma) / L[s][s];
}

int main() {
    vector<vector<float>> A = {
        {9, -9, -6, 9},
        {-9, 13, 10, -11},
        {-6, 10, 17, -5},
        {9, -11, -5, 15}
    };

    int n = A.size();


    vector<vector<float>> L(n, vector<float>(n, 0.0));

    for (int s = 0; s < n; s++) {
        //przekatna
        L[s][s] = lss(A, L, s);

        //poniżej przekątnej
        for (int i = s + 1; i < n; i++) {
            L[i][s] = lis(A, L, s, i);
        }
    }

    cout << "Macierz L:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << L[i][j]<< " ";
        }
        cout << endl;
    }

    vector<float> b = {-24, 30, 28, -29};
    vector<float> y(n, 0);

    for (int i = 0; i < n; i++) {
        float suma = 0;
        for (int j = 0; j < i; j++) {
            suma += L[i][j] * y[j];
        }
        y[i] = (b[i] - suma) / L[i][i];
    }

    vector<float> x(n, 0);

    for (int i = n-1; i >= 0; i--) {
        float suma = 0;
        for (int j = i+1; j < n; j++) {
            suma += L[j][i] * x[j];
        }
        x[i] = (y[i] - suma) / L[i][i];
    }

    for (int i = 0; i < n; i++) {
        cout << "x" << i+1 << "= " << x[i] << endl;
    }

    return 0;
}