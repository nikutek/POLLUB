#include <stdio.h>

int szescian(n) {
    return n*n*n;
}

int main(void) {
    printf("Hello, World!\n");
    for (int setki = 1; setki <= 10; setki++) {
        for (int dziesiatki = 0; dziesiatki <= 10; dziesiatki++) {
            for ( int jedosci = 0; jedosci <= 10; jedosci++) {
                int zlaczone = setki*100 + dziesiatki*10 + jedosci;
                int sumaSzescianow = szescian(setki) + szescian(dziesiatki) + szescian(jedosci);
                if(sumaSzescianow == zlaczone & zlaczone<1000) {
                    printf("%d\n", zlaczone);
                }
            }
        }
    }

    return 0;
}
