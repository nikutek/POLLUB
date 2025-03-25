//
// Created by user on 14-Jan-25.
//

#include <stdio.h>
#include <stdlib.h>


float** stworz(int wiersze,int kolumny){
    float** tablica = (float**)malloc(wiersze*sizeof(float*));
    if (tablica == NULL) {
        printf("Memory could not be allocated");
    }
    for (int i = 0; i < wiersze; i++) {
        tablica[i] = (float*)malloc(kolumny*sizeof(float));
        if (tablica[i] == NULL) {
            printf("Memory could not be allocated");
        }
    }
    int h = 1;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            tablica[i][j] = h;
            h++;
        }
    }
    return tablica;
}

void wyswietl(float** tablica, int wiersze, int kolumny) {
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            printf("%.2f ", tablica[i][j]);
        }
        printf("\n");
    }
}