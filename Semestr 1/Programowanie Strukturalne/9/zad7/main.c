#include <stdio.h>

void findMax(int n, int nums[]) {
    int max = nums[0];
    for (int i=0; i<n; i++) {
        if(nums[i] > max) {
            max = nums[i];
        }
    }
}

int main(void) {
    printf("Hello, World!\n");
    int n =3;
    int nums[n];
    int max;

    for(int i=1;i<=n;i++) {
        int num;
        printf("Enter a number: ");
        num = scanf("%d", &num);
        nums[i] = num;
    }
    return 0;
}
