#include <stdio.h>

int main(void) {
    float a,b;
    printf("Podaj: a b\n");
    scanf("%f %f",&a, &b);
    printf("srednia arytmetyczna a i b to: %0.2f \n", (a+b)/2);
    return 0;
}
