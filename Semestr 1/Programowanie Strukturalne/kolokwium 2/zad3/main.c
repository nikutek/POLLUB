//
// Created by user on 15-Jan-25.
//
#include <stdio.h>
#include <stdlib.h>

//Napisz funkcję obliczającą sumy w wierszach i iloczyny w kolumnach w dwuwymiarowej tablicy liczb rzeczywistych i zwracającą wyniki, jako dwie tablice. Rozmiary (n, m) i elementy danej tablicy tab są parametrami przekazanymi do funkcji. Tablica iloczynów w kolumnach iloczynK jest przekazana z funkcji jako parametr wskaźnikowy, wskaźnik do utworzonej tablicy sum w wierszach sumaW jest przekazany poprzez return.
// funkcji może wyglądać następująco:
//float * sumaW(int n, int m, float tab[][m], float * iloczynK);
//Napisz program, w którym wczytane są dane, wywołana funkcja, wyświetlone wyniki.

void wyswietlTablice2d(int n, int m, float **tab) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("%2.2f\t",tab[i][j]);
        }
        printf("\n");
    }
}

float *sumaW(int kolumny, int wiersze, float **tab, float *iloczynK) {
    float *sumaWierszy = (float *)malloc(sizeof(float)*wiersze);
    for(int i=0;i<kolumny;i++) {
        float sumaWiersza=0;
        for(int j=0;j<wiersze;j++) {
            sumaWiersza+=tab[i][j];
        }
        printf("suma wiersza %d %2.2f\n",i, sumaWiersza);
        sumaWierszy[i] = sumaWiersza;
    }

    for(int i=0;i<wiersze;i++) {
        float iloczynKolumny = 1;
        for(int j=0;j<kolumny;j++) {
            float num = tab[j][i];
            iloczynKolumny *= num;
        }
        printf("Iloczyn kolumny %d: %.2f\n",i, iloczynKolumny);
        iloczynK[i] = iloczynKolumny;
    }


    return sumaWierszy;
}



int main() {
    int n, m;
    printf("Ilosc kolumn:");
    scanf("%d", &n);
    printf("Ilosc wierszy:");
    scanf("%d", &m);

    float **tab = (float **) malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        tab[i] = (float*)malloc(m * sizeof(float));
    }
    int q=1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tab[i][j] = q;
            q++;
        }
    }

    wyswietlTablice2d(n, m, tab);
    float* iloczynK = (float*)malloc(n * sizeof(float));
    float *sumaWierwszy = sumaW(n, m, tab, iloczynK);

    return 0;
}
