#include <stdio.h>
#include <stdlib.h>

void czySczesliwy(int numer) {
    if(numer%10 + numer/10%10 + numer/100%10 == numer/1000%10 + numer/10000%10 + numer/100000%10) {
        printf("numer jest szczesliwy");
    } else {
        printf("numer nie jest szczesliwy");
    }
}

int main(void) {
    czySczesliwy(10);
    return 0;
}
