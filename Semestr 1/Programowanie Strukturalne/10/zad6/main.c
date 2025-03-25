#include <stdio.h>

int sprawdz(int oceny[], int ilosc) {
    for (int i=0; i<ilosc; i++) {
        if (oceny[i] <=2) {
            return 0;
        }
    }
}

int main(void) {
    int oceny[] = {3,4,5,2,5,6};
    int czyWszyscyZdali = sprawdz(oceny, 6);
    if (sprawdz(oceny, 6) == 0) {
        printf("Nie wszyscy zdali\n");
    } else {
        printf("Wszyscy zdali\n");
    }
}