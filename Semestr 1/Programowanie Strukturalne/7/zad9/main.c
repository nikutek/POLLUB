#include <stdio.h>

int main(void) {
    int n = 10;
    int arr[100];

    for (int i = 0; i < 100; i++) {
        arr[i] = i + 1;
    }

    for (int i = 2; i < 100; i++) {
        for (int j = i; j < 100; j++) {
            if(arr[j]%i == 0) {
                arr[j] = 0;
            }
        }
    }

    int i =0;
    int znaleziono=0;
    while(znaleziono<n) {
        if(arr[i]!=0) {
            printf("%d\n", arr[i]);
            znaleziono++;
        }
        i++;
    }
    return 0;
}
