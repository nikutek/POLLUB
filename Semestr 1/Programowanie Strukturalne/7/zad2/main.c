#include <stdio.h>

int main(void) {
    int n = 5;
    int evenSum=0;
    for (int i = 0; i < n; i++) {
        int num;
        printf("Podaj liczbe %d/%d: \n", i+1,n);
        scanf("%d", &num);
        if(num%2==0) {
            evenSum+=num;
        }
    }

    printf("Suma liczb parzystych: %d\n", evenSum);
    return 0;
}
