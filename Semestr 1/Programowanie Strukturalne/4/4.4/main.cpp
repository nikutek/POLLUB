#include <math.h>
#include <stdio.h>

void figury(float a, float b, float h, float r) {
    printf("Objetosc szescianu: %f \n", a*a*a);
    printf("Pole powierzchni prostopadloscianu: %f \n", a*b*2 + a*h*2 + b*h*2);
    printf("Objetosc walca: %f \n", r *M_PI* h);
}

int main(void) {
    float a, b, h, r;
    printf("Podaj: a b h r\n");
    scanf("%f %f %f %f", &a, &b, &h, &r);

    figury(a, b, h, r);

}