#include <stdio.h>
#define STATUS "Student"
#define SREDNIA 4.0

void printInfo(char imie[], char nazwisko[], int wiek, char plec[]) {

    printf("Imie: %s Nazwisko: %s plec: %s wiek: %i \n", imie, nazwisko, plec, wiek);
    printf("Status: %s Srednia: %f", STATUS, SREDNIA);
}

int main(void)
{
    char imie[20], nazwisko[20], plec[20];
    int wiek;
    printf("Podaj: imie nazwisko wiek plec\n");
    scanf("%s, %s, %d, %s", &imie, &nazwisko, &wiek, &plec);

    printInfo(imie, nazwisko, wiek, plec);
    return 0;
}
