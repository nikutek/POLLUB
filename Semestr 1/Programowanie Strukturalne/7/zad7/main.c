#include <stdio.h>

int silniaIter(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res*=i;
    }
    return res;
}

int silniaRek(n) {
    if(n==1) {
        return 1;
    }
    return n * silniaRek(n-1);
}

int main(void) {
    int n = 5;
    printf("Iteracyjnie %d! = %d\n", n, silniaIter(n));
    printf("Rekurencyjnie %d! = %d\n", n, silniaRek(n));
    return 0;
}
