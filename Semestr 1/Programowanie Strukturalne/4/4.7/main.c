#include <math.h>
#include <stdio.h>


void poCzasie(int lata, int miesiace, int miesiaceWPrzod) {
    while(miesiaceWPrzod>=12) {
        lata += 1;
        miesiaceWPrzod -= 12;
    }
    miesiace += miesiaceWPrzod;
    if(miesiace>=12) {
        lata += 1;
        miesiace -= 12;
    }
    printf("%d lat, %d miesiecy", lata, miesiace);
}

int main(void) {
    int lata, miesiace, miesiaceWPrzod;
    printf("Podaj ile masz lat, miesiecy: \n");
    scanf("%d %d", &lata, &miesiace);
    printf("Ile miesiecy do przodu? ");
    scanf("%d", &miesiaceWPrzod);

    poCzasie(lata, miesiace, miesiaceWPrzod);
    return 1;
}