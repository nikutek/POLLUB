//
// Created by user on 24-Feb-25.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <valarray>
using namespace std;

void zad2() {
  int size;
  int a;
  int b;
  cout << "Dlugosc tablicy: ";
  cin >> size;
  cout << "dolny zakres liczb losowanych: ";
  cin >> a;
  cout << "gorny zakres liczb losowanych: ";
  cin >> b;

  int *tab = new int[size];
  for (int i = 0; i < size; i++) {
    tab[i] = rand() % (b - a+1) + a;
  }
  int min = tab[0];
  for (int i = 1; i < size; i++) {
    if (tab[i] < min) {
      min = tab[i];
    }
  }
  cout << min << " ";
  for (int i = 2; i < ceil(round(sqrt(min))); i++) {
    if (min % i ==0) {
      cout << "nie jest liczba pierwsza" << endl;
      exit(0);
    }
  }
  cout << "jest liczba pierwsaza" << endl;
  delete [] tab;
};
void zad3() {
  int size;
  cout << "Dlugosc tablicy: ";
  cin >> size;
  int * tab = new int[size];
  int zliczone[10] = {0*10};

  for (int i = 0; i < size; i++) {
    tab[i] = rand() % (10);
  }

  for (int i = 0; i < size; i++) {
      zliczone[tab[i]] +=1;
  }

  for (int i = 0; i < 10; i++) {
    cout << i<<":" <<zliczone[i] << endl;
  }

  delete [] tab;
};

void zad4() {
  int size;
  int a;
  int b;
  cout << "Dlugosc tablicy: ";
  cin >> size;
  cout << "dolny zakres liczb losowanych: ";
  cin >> a;
  cout << "gorny zakres liczb losowanych: ";
  cin >> b;

  int *tab = new int[size];
  for (int i = 0; i < size; i++) {
    tab[i] = rand() % (b - a+1) + a;
  }
  int max = tab[0];
  for (int i = 1; i < size; i++) {
    if (tab[i] > max) {
      max = tab[i];
    }
  }
  int ilosc =0;
  for (int i = 0; i < size; i++) {
    if (tab[i] == max) {
      ilosc++;;
    }
  }
  cout << "Najwieksza wartosc: "<< max << endl;
  cout << "Ilosc wystapien: "<< ilosc << endl;

  delete [] tab;
};
void zad5() {
  int size;
  cout << "Dlugosc tablicy: ";
  cin >> size;

  int **tab = new int*[size];
  for (int i = 0; i < size; i++) {
    tab[i] = new int[size];
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      tab[i][j] = rand()%115 + 7;
    }
  }
  int sumaGora=0;
  int sumaDol=0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (j>i) {
        sumaGora+=tab[i][j];
      } else if (i>j) {
        sumaDol+=tab[i][j];
      }
    }
  }
  cout << "Srednia elementow powyzej glownej diagonali: "<< sumaGora/(size*size -size)/2 << endl;
  cout << "Srednia elementow ponizej glownej diagonali: "<< sumaDol/(size*size -size)/2 << endl;
};



int main() {
  srand(time(0));
  cout << "1) zadanie 1.2" << endl;
  cout << "2) zadanie 1.3" << endl;
  cout << "3) zadanie 1.4" << endl;
  cout << "4) zadanie 1.5" << endl;
  cout << "5) wyjscie z programu" << endl;
  int wybor;
  cout << "Numer:";
  cin >> wybor;

  switch (wybor) {
    case 1:
      zad2();
      break;
    case 2:
      zad3();
      break;
    case 3:
      zad4();
      break;
    case 4:
      zad5();
    case 5:
      exit(0);

  }
  return 0;
}