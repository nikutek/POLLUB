#include <stdio.h>

void wyswietl(char znak, int ileRazy) {
    for (int i=0; i<ileRazy; i++) {
        printf("%c", znak);
        fflush( stdout );
    }
}

int main(void) {;
    wyswietl('A', 5);
    return 0;
}
