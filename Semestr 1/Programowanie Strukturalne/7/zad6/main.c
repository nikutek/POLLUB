#include <stdio.h>

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int power(n,k) {
    int res = n;
    for (int i = n; i<= k; i++) {
        res*=n;
    }
    return res;
}

int main(void) {
    int k =5;
    float x = 1;
    float res = x;
    for (int i = 1; i <= k; i++) {
        if(i%2==1) {
            res -= power(x,1+2*i) / factorial(1+2*i);
        } else {
            res += power(x,1+2*i) / factorial(1+2*i);
        }
    }

    printf("sin x = %f", res);
    return 0;
}
