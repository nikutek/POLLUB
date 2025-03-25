//
// Created by user on 15-Jan-25.
//
#include <stdio.h>
#include <stdlib.h>

//Bank oferuje lokaty: kwartalną oprocentowaną p 8% (w skali roku) i roczną oprocentowaną p 9%. Klient wpłaca x zł na rok. Napisz funkcję zwracającą w parametrach wskaźnikowych uzyskane po roku wypłaty dla obu wariantów lokat. Wczytanie danych zrealizuj w main(). Wywołaj tę funkcję, wyświetl wyniki.

void kwartalnie(float *kwota) {
    for (int i = 0; i < 4; i++) {
        *kwota *= (float)1.02;

    }
}

void rocznie(float *kwota) {
    *kwota *= (float)1.09;
}

int main() {
    float kwotaKwartalnie = 1000;
    float kwotaRocznie = 1000;
    kwartalnie(&kwotaKwartalnie);
    rocznie(&kwotaRocznie);
    printf("kwartalnie %.2f \nRocznie: %.2f", kwotaKwartalnie, kwotaRocznie);
    return 0;
}
