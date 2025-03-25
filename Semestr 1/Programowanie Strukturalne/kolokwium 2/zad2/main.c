//
// Created by user on 15-Jan-25.
//
#include <stdio.h>
#include <stdlib.h>

//Napisz, wykorzystując notację tablicową, funkcje: wczytaj, wyświetl, min, suma, ileRazy, które dla n elementowej jednowymiarowej tablicy liczb całkowitych pozwolą na:
//- wczytanie danych do tablicy z klawiatury,
//- wyświetlenie elementów tablicy na ekranie,
//- obliczenie najmniejszej wartości,
//- obliczenie sumy elementów tablicy,
//- zliczenie, ile razy wystąpiła w tablicy podana przez użytkownika liczba.
//W funkcji main zadeklaruj tablicę tab1 o stałej długości N (stała). Wczytaj i wyświetl elementy tej tablicy, oblicz min i sumę jej elementów. Sprawdź, ile razy wystąpiła w nich podana liczba.

void wczytaj(int *tab, int n) {
  for (int i = 0; i < n; i++){
    printf("Podaj liczbe %d: ", i);
    scanf("%d", &tab[i]);
  }
}

void wyswietl(int *tab, int n){
  for (int i = 0; i < n; i++) {
    printf("%d, ", tab[i]);
  }
  printf("\n");
}

int min(int *tab, int n) {
  int min = tab[0];
  for (int i = 1; i < n; i++) {
    if (tab[i] < min) {
      min = tab[i];
    }
  }
  return min;
}

int suma(int *tab, int n) {
  int suma = 0;
  for (int i = 0; i < n; i++) {
    suma += tab[i];
  }
  return suma;
}

int ileRazy(int *tab, int n, int szukana) {
  int razy=0;
  for (int i = 0; i < n; i++) {
    if (tab[i] == szukana) {
      razy++;
    }
  }
  return razy;
}

int main() {
  int n;
  printf("dlugosc tablicy:");
  scanf("%d", &n);
  int *tab = malloc(sizeof(int) * n);

  wczytaj(tab, n);
  wyswietl(tab, n);

  printf("minimum = %d\n", min(tab, n));
  printf("suma = %d\n", suma(tab, n));
  printf("ile razy wystapila cyfra 1: %d\n", ileRazy(tab, n, 1));

  return 0;
}
