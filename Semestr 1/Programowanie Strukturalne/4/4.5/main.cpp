#include <stdio.h>

float policzSrednia(int a, int b) {
    return 1.0*(a + b)/2;
}

int main(void) {
    int a,b;
    printf("Podaj: a b\n");
    scanf("%d %d",&a, &b);
    printf("srednia arytmetyczna a i b to: %f \n", policzSrednia(a,b));
    return 0;
}