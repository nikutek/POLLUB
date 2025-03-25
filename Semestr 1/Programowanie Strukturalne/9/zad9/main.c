//
// Created by user on 14-Jan-25.
//
#include <stdio.h>
#include <stdlib.h>

float obliczCene(int ilosc){
  float cena = 20.0;
  if(ilosc<10){
    return cena*1.2;
  } else {
    return cena;
  }
}

float obliczKoszt(int ilosc){
  return ilosc * obliczCene(ilosc);
}

int main(){
  int ilosc;
  printf("Podaj ilosc sztuk:");
  scanf("%d", &ilosc);

  printf("Koszt za %d sztuk: %.2f", ilosc, obliczKoszt(ilosc));
  return 0;
}