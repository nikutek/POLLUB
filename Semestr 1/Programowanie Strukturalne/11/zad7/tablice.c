//
// Created by user on 14-Jan-25.
//
#include <stdio.h>
#include <stdlib.h>
#include "tablice.h"

float* stworz(int n){
  float* tab = (float*)malloc(sizeof(float)*n);
  if(tab == NULL){
    return NULL;
  }
  for(int i=0;i<n;i++){
    float random = (rand()%1000);
    tab[i] = random;
  }
  return tab;
  }

void wyswietl(float* tab, int n){
  for(int i=0;i<n;i++){
    printf("Tab[%d] = %.2f\n",i,tab[i]);
  }
}

void usun(float* tablica){
  free(tablica);
}