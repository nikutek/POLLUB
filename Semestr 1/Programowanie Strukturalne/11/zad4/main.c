#include <stdio.h>
#include <stdlib.h>
#include "tabliceDyn.h"

int main(void) {

    int* tablica = stworzTablice(5);
    wyswietlTablice(tablica);
    usunTablice(tablica);
    printf("Po zwolnieniu pamieci:\n");
    wyswietlTablice(tablica);

    return 0;
}
