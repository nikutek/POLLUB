#include <math.h>
#include <stdio.h>

float poleTrojkata(int bok1, int bok2, int bok3) {
    float p = (bok1 + bok2 + bok3) / 2.0;
    return sqrt(p * (p - bok1) * (p - bok2) * (p - bok3));
}

int main(void) {
    printf("Hello, World!\n");
    printf("%0.2f\n", poleTrojkata(2, 2, 3));
    return 0;
}
