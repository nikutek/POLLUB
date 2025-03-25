//
// Created by user on 14-Jan-25.
//
#include "tablice.c"
#include <stdio.h>
#include <stdlib.h>

void znajdzNajlepszy(float* tablica) {
    float min;
    min  = tablica[0];
    int numer;
    for (int i = 1; i < sizeof(*tablica)/sizeof(float); i++) {
        if (tablica[i] < min) {
            min = tablica[i];
            numer = i;
        }
    }
    printf("Nr. %d mial czas %f", numer, min);
}

int main(){
    float* tablica = stworz(300);
    wyswietl(tablica, 300);
    znajdzNajlepszy(tablica);

}
