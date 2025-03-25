#include <stdio.h>

int main(void) {
    int n = 5;
    for (int i=0; i<n;i++) {
        int placa;
        printf("Placa pracownika %d: \n", i+1);
        scanf("%d", &placa);
        if(placa<5000) {
            printf("Po podwyzce: %f\n", placa*1.1);
        } else if (placa>=5000) {
            printf("Po podwyzce: %f\n", placa*1.05);
        }
    }
    return 0;
}
