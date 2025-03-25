#include <stdio.h>

int iloczynN(int n, int *iloczyn){
    for (int i = 0; i < n; i++){
        printf("Podaj liczbe (0-100): ");
        int num;
        scanf("%d", &num);
        if(num >=1 && num <= 100){
            *iloczyn *= num;
        } else {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    printf("Hello, World!\n");
    int n=3;
    int iloczyn = 1;

    iloczynN(n, &iloczyn);

    printf("Iloczyn N = %d\n", iloczyn);
    return 0;
}
