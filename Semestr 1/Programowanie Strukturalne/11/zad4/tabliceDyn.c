//
// Created by student on 09.01.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "tabliceDyn.h"

int *stworzTablice(int length) {
    int *tablica;

    tablica = (int *)malloc(length * sizeof(int));
    if (tablica == NULL) {
        printf("Erreur\n");
        exit(1);
    }
    for (int i = 0; i <= length; i++) {
        tablica[i] = i;
    }
    return tablica;
}

void wyswietlTablice(int *tablica) {
    for (int i=0; i<=sizeof(*tablica); i++) {
        printf("%d\t", tablica[i]);
    }
    printf("\n");
}

void usunTablice(int *tablica) {
    free(tablica);
    tablica = NULL;
}
