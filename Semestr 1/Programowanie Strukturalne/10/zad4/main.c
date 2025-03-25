#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int iloczynPrzekatnej(int nums[][3], int size) {
    int iloczyn = 1;
    for (int i = 0; i < size; i++) {
            iloczyn *= nums[i][i];
    }
    return iloczyn;
}

int main(void) {
    int plansza[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printf("Iloczyn przekatnej: %d\n", iloczynPrzekatnej(plansza, 3));
}
