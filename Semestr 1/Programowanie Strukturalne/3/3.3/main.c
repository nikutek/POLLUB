#include <stdio.h>
#define STATUS "Student"
#define SREDNIA 4.0

int main(void)
{
    char imie[20], nazwisko[20], plec[20];
    int wiek;
    printf("Podaj: imie nazwisko wiek plec\n");
    scanf("%s, %s, %d, %s", &imie, &nazwisko, &wiek, &plec);

    printf("Imie: %s Nazwisko: %s plec: %s \n", imie, nazwisko, plec);
    printf("Status: %s Srednia: %f", STATUS, SREDNIA);
    return 0;
}
