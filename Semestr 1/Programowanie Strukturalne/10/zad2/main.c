#include <stdio.h>



void wczytaj(int *tablica) {
    for (int i=0; i<sizeof(tablica); i++) {
        printf("Podaj liczbe: ");
        scanf("%d", &tablica[i]);
    }
}

void wyswietl (int *tablica) {
    for (int i=0; i<sizeof(tablica); i++) {
        printf("%d \n", tablica[i]);
    }
}

int max(int *tablica) {
    int max = tablica[0];
    for (int i=0; i<sizeof(tablica); i++) {
        if(tablica[i] > max) {
            max = tablica[i];
        }
    }
    return max;
}


int suma(int *tablica) {
    int suma =0;
    for (int i=0; i<sizeof(tablica); i++) {
        suma += tablica[i];
    }
    return suma;
}

int ileRazy(int n,int *tablica) {
    int ileRazy = 0;
    for (int i=0; i<sizeof(tablica); i++) {
        if(tablica[i] == n) {
            ileRazy++;
        }
    }
    return ileRazy;
}

int main(void) {
    int n = 5;
    int tablica[n];
    wczytaj(tablica);
    wyswietl(tablica);
    printf("max: %d\n", max(tablica));
    printf("suma: %d\n", suma(tablica));
    printf("Podaj liczbe ktorej ilosc chcesz policzyc: ");
    int liczba;
    scanf("%d",&liczba);
    printf("%d\n", ileRazy(n,tablica));
}