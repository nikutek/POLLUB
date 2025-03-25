//
// Created by student on 09.01.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int losuj() {
    srand(time(NULL));
    return rand();
}

int stworzTablice() {
    int* tablica;

    tablica = (int *)malloc(100*sizeof(int));
    if(!tablica) {
        printf("Erreur\n");
        exit(1);
    }
    for(int i = 0; i < 100; i++) {
        tablica[i] = losuj();
    }
    return tablica;
}