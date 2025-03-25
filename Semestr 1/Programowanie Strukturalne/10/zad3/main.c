#include <stdio.h>
#include <stdlib.h>


void wyswietl (int *tablica) {
    for (int i=0; i<sizeof(tablica); i++) {
        printf("%d \n", tablica[i]);
    }
}

int min(int *tablica) {
    int min = tablica[0];
    for (int i=0; i<sizeof(tablica); i++) {
        if(tablica[i]< min) {
            min = tablica[i];
        }
    }
    return min;
}


float srednia(int *tablica) {
    int suma =0;
    for (int i=0; i<sizeof(tablica); i++) {
        suma += tablica[i];
    }
    return 1.0*suma/sizeof(tablica);
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

void losuj(int *tablica) {
    for (int i=0; i<sizeof(tablica); i++) {
        tablica[i] = rand()%10;
    }
}

int main(void) {
    int n = 10;
    int tablica[n];
    losuj(tablica);
    wyswietl(tablica);
    printf("min: %d\n", min(tablica));
    printf("srednia: %3f\n", srednia(tablica));
    printf("Podaj liczbe ktorej ilosc chcesz policzyc: ");
    int liczba;
    scanf("%d",&liczba);
    printf("%d\n", ileRazy(n,tablica));
}