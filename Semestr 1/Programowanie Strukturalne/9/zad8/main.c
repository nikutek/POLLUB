//
// Created by user on 14-Jan-25.
//
#include <stdio.h>
#include <stdlib.h>

void naliczOdsetki(float* lokata1, float* lokata2) {
  *lokata1 = *lokata1 * 1.08;
  *lokata2 = *lokata2 * 1.1;
}

int main(){
  float kwota1;
  float kwota2;

  printf("Podaj kwotę na lokatę 1: ");
  scanf("%f", &kwota1);
  printf("Podaj kwotę na lokatę 2: ");
  scanf("%f", &kwota2);

  naliczOdsetki(&kwota1, &kwota2);

  printf("Kwota po roku lokacie nr 1: %f\n", kwota1);
  printf("Kwota po roku na lokacie nr 2: %f", kwota2);

  return 0;
}

