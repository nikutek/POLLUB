#include <stdio.h>

float srednia(int sum, int n) {
    return 1.0*sum/n;
}

int main(void) {
    int oddSum = 0;
    int oddN =0;
    int evenSum=0;
    int evenN=0;
    while(1) {
        printf("Podaj liczbe (0=stop): ");
        int num;
        scanf("%i", &num);
        if(num == 0) {
            break;
        } else if (num%2==0) {
            evenSum+=num;
            evenN++;
        } else {
            oddSum+=num;
            oddN++;
        }
    }

    printf("Srednia liczb parzystych: %f\n",srednia(evenSum, evenN));
    printf("Srednia liczb nieparzystych: %f\n",srednia(oddSum, oddN));

    return 0;
}
