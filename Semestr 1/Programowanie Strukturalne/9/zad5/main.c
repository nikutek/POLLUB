#include <stdio.h>

void czesci(double *num) {
    int calkowita = (int)*num;
    printf("%d\t", calkowita);
    double ulamek = *num - calkowita;
    printf("%f\t", ulamek);
}

int main(void) {
    printf("Hello, World!\n");
    double num = 3.14;
    double *ptr = &num;
    czesci(ptr);
    return 0;
}
