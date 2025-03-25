//
// Created by user on 14-Jan-25.
//
#include <stdio.h>
#include <stdlib.h>

int* stworz(int n){
    int* tablica = (int*)malloc(sizeof(int) * n);
    if(tablica == NULL){
        printf("Erreur\n");
        return NULL;
    }
    for(int i = 0; i < n; i++){
      printf("Tablica[%d]: ", i, tablica[i]);
      scanf("%d", &tablica[i]);
    }
    return tablica;
}

void wyswietl(int* tablica, int n){
    for(int i = 0; i < n; i++) {
        printf("Tablica[%d]: %d\n", i, tablica[i]);
    }
}

void usun(int* tablica) {
    free(tablica);
}