//
// Created by user on 24-Feb-25.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void przydzielPamiec1D(int *&tab, int n){
  tab=new int[n];
}
void przydzielPamiec2D(int **&tab, int w, int k){
  tab=new int*[w];
  for(int i=0; i<w; i++){
    tab[i]=new int[k];
  }
}

void wypelnijTablice1D(int *tab, int n, int a, int b){
  for (int i=0; i<n; i++){
    tab[i]=rand()%(b-a+1)+a;
  }
}
void wypelnijTablice2D(int **tab, int w, int k, int a, int b) {
  for (int i=0; i<w; i++) {
    for (int j=0; j<k; j++) {
      tab[i][j]=rand()%(b-a+1)+a;
    }
  }
}
void usunTablice1D(int *&tab){
  delete tab;
}
void usunTablice2D(int **&tab, int w) {
  for (int i=0; i<w; i++) {
    delete tab[i];
  }
  delete tab;
}
void wyswietl1D(int* tab, int n) {
  cout << "1D: " << endl;
  for (int i=0; i<n; i++){
    cout << tab[i] << " ";
  }
  cout << endl;
}
void wyswietl2D(int** tab, int w, int k) {
  cout << "2D: " << endl;
  for (int i=0; i<w; i++) {
    for (int j=0; j<k; j++) {
      cout << tab[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  int *tab1d = new int[3];
  int **tab2d = new int*[3];

  przydzielPamiec1D(tab1d, 3);
  wypelnijTablice1D(tab1d, 3, 0, 10);
  wyswietl1D(tab1d, 3);
  usunTablice1D(tab1d);

  przydzielPamiec2D(tab2d,3,3);
  wypelnijTablice2D(tab2d,3,3,0,10);
  wyswietl2D(tab2d,3,3);
  usunTablice2D(tab2d,3);


  return 0;
}
