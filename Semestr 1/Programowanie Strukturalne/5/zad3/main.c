#include <math.h>
#include <stdio.h>

void funkcjaKwadratowa(int a, int b, int c) {
    float delta = b*b - 4*a*c;
    if (delta < 0) printf("0;");
    else if(delta==0) {
        printf("%f",(-b/(2*a)));
    } else {
        printf("%f",(-b+sqrt(delta))/(2*a));
        printf("%f",(-b-sqrt(delta))/(2*a));
    }
}

int main(void) {
    int a= 2;
    int b= 3;
    int c= 4;
    funkcjaKwadratowa(a,b,c);
    return 0;
}
