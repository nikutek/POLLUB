//
// Created by user on 14-Jan-25.
//
#include <stdio.h>
#include <stdlib.h>
#include "tablice.h"

int main(){
  int* tablica = stworz(5);
  wyswietl(tablica, 5);
  usun(tablica);
  wyswietl(tablica, 5);
}