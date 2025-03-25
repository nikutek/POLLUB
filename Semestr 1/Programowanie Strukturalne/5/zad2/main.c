#include <stdio.h>
#include <stdbool.h>

bool czyNalezy(int x, int y) {
    return (x>=-1 && x<=1 && y>=-1 && y<=1);
}

int main(void) {
    printf("%s\n", czyNalezy(1,3)?"nalezy":"nie nalezy");

    return 0;
}
