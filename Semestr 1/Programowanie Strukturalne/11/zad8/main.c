//
// Created by user on 14-Jan-25.
//
#include <stdio.h>
#include <stdlib.h>
#include"tablice2d.c"


float* sumy(float** tablica, int wiersze, int kolumny, float* sumaKolumn) {
    float* sumaWierszy = (float*)malloc(wiersze*sizeof(float));
    for (int i = 0; i <= wiersze; i++) {
        float suma = 0;
        for (int j = 0; j < kolumny; j++) {
            suma += tablica[i][j];
        }
        // printf("wiersze suma: %.2f\n", suma);
        sumaWierszy[i] = suma;
    }

    for (int i = 0; i < kolumny-1; i++) {
        float suma = 0;
        for (int j = 0; j <= wiersze; j++) {
            suma+= tablica[j][i];
        }
        // printf("kol suma: %.2f\n", suma);
        sumaKolumn[i] = suma;
    }

    return sumaWierszy;
}

int main() {
    int wiersze=3;
    int kolumny=2;
    float* sumaKolumn = (float*)malloc(kolumny*sizeof(float));

    float** tablica = stworz(wiersze, kolumny);
    wyswietl(tablica, wiersze, kolumny);
    float* sumaWierszy = sumy(tablica, kolumny, wiersze, sumaKolumn);

    for (int i = 0; i < kolumny; i++) {
        printf("suma kolumny %d: %f\n", i, sumaKolumn[i]);
    }
    printf("\n");
    for (int i = 0; i < wiersze; i++) {
        printf("suma wiersza %d: %f\n", i, sumaWierszy[i]);
    }
    
    return 0;
}
