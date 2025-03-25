#include <math.h>
#include <stdio.h>

float func1(int t, int a) {
    if(t==0 || t==1 || t==2 || t==3) {
        printf("%f", 1+cos(a)/2);
    } else if ( t==4 || t==6 || t==7) {
        printf("%f", sqrt(a*a+1));
    } else if (t==8) {
        printf("%f", 1-sin(a));
    } else {
        printf("Nieprawidłowe t");
    }
}

float func2(int t, int a) {
    switch(t) {
        case 0:
        case 1:
        case 2:
        case 3:
            printf("%f",1+cos(a))/2;break;
        case 4:
            case 6:
        case 7:
            printf("%f", sqrt(a*a+1)); break;
        case 8:
            printf("%f", 1-sin(a)); break;
        default:
            printf("Nieprawidłowa zmienna t");
        return 0;
    }
}

int main(void) {
    int a = 30;
    int t = 5;
    func1(t, a);
    func2(t, a);
    return 1;
}
