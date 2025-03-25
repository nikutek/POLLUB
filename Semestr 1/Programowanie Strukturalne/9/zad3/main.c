#include <stdio.h>

void zamiana(int *p1, int *p2) {
    int suma = *p1 + *p2;
    int roznica = *p1 - *p2;

    *p1 = suma;
    *p2 = roznica;
}

int main(void) {
    printf("Hello, World!\n");
    int num1 = 3;
    int num2 = 5;

    int *ptr1 = &num1;
    int *ptr2 = &num2;

    printf("%d , %d\n", *ptr1, *ptr2);

    zamiana(ptr1, ptr2);

    printf("%d , %d\n", *ptr1, *ptr2);
    return 0;
}


