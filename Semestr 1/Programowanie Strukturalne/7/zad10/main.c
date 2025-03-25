#include <stdio.h>

int kw(n) {
    return n*n;
}

int main(void) {
    int n=100;
    for(int a=1;a<=n;a++) {
        for(int b=1;b<=n;b++) {
            for(int c=1;c<=n;c++) {
                if(kw(a) + kw(b) == kw(c)) {
                    printf("a=%d, b=%d, c=%d\n",a,b,c);
                }
            }
        }
    }
    return 0;
}
