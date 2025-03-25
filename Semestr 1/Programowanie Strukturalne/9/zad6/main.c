#include <stdio.h>

void liczba(const int num, const int *dodatnich, const int *zero) {
    if(num == 0) {
        zero++;
    } else if (num > 0) {
        dodatnich++;
    }
}

int main(void) {
    printf("Hello, World!\n");
    int n = 3;
    int dodatnich=0;
    int zero=0;
    int *ptrDodatnich = &dodatnich;
    int *ptrZero=&zero;
    for (int i = 0; i <= n; i++) {
        int num;
        printf("Podaj liczbe: ");
        scanf("%d", &num);
        liczba(num, ptrDodatnich, ptrZero);
    }
    printf("ilość zer: %d\nilość dodatnich: %d",zero, dodatnich);

    return 0;
}
