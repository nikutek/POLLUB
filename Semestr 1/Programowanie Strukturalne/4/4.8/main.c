#include <math.h>
#include <stdio.h>

float funkcja1(x) {
    return 10*cos(x) - 0.1*pow(x,2) + sin(x) + sqrt(4*pow(x,2) + 7);
}

float funkcja2(x, e) {
    return log(x+5) + pow(e, x+1) - abs(tan(x)+1);
}

float funkcja3(a) {
    return (pow(sin(a),2) + 0.5) / (pow(cos(a),4) + pow(tan(pow(a,4)),4));
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
