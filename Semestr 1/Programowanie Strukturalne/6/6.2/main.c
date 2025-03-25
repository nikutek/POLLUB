#include <stdbool.h>
#include <stdio.h>

void sredniaWhile() {
    int sum = 0;
    int n=0;

    while(true) {
        int num;
        printf('Enter a number (0 stops): ');
        scanf("%i", &num);
        if(num==0) break;
        sum+=num;
        n++;
    }
    printf("Average = %f", 1.0*sum/n);
}

void sredniaDoWhile() {
    int sum = 0;
    int n=0;
    int num;
    do {
        printf('Enter a number (0 stops): ');
        scanf("%i", &num);
        sum+=num;
        n++;
    } while(num!=0);
}

int main(void) {
    sredniaWhile();
    sredniaDoWhile();
    return 1;
}
