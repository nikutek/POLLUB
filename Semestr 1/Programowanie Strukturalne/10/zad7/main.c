//
// Created by user on 14-Jan-25.
//
#include <stdio.h>
#include <stdlib.h>

void zamiana(int tablica[][], int n) {
    int min = tablica[0][0];
    int max = tablica[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tablica[i][j] < min) {
                min = tablica[i][j];
            } else if (tablica[i][j] > max) {
                max = tablica[i][j];
            }
        }
    }
    printf("Minimum element is %f\n", min);
    printf("Maximum element is %f\n", max);
}

int menu() {
    printf("1. zamiana miejscami elementu maksymalnego i minimalnego\n");
    printf("2. zapisanie elementów tablicy w odwrotnej kolejności\n");
    printf("3. utworzenie nowej tablicy Y zawierającej kwadraty danych liczb, oraz nowej tablicy Z zawierającej sześciany danych liczb.\n");
    int choice;
    scanf("%d", &choice);
    return choice;
}

int main() {
    int n;
    printf("Podaj dlugosc tablicy: ");
    scanf("%d", &n);
    int tablica[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tablica[i][j] = i+j;
        }
    }
    zamiana(tablica, n);
    return 0;
}
