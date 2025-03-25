#include <stdio.h>

int main(void) {
    int n=5;
    int nums[n];


    for (int i=0; i<n; i++) {
        printf("Podaj numer: \n");
        scanf("%d", &nums[i]);
    }

    int roznica = nums[1]-nums[0];

    for (int i=1; i<n-1; i++) {
        if(nums[i+1]-nums[i] != roznica ) {
            printf("Podane liczby nie tworza ciagu arytmetycznego\n");
            break;
        }

        printf("Podane liczby tworza ciag arytmetyczny\n");
    }
    return 0;
}
