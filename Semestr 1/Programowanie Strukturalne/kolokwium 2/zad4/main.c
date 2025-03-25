//
// Created by user on 15-Jan-25.
//
#include <stdio.h>
#include <stdlib.h>

//Zamień tekst „Jestem mezrtsim C” w tablicy tak aby drugi wyraz mezrtsim został wyświetlony od końca. Użyj funkcji zamien. Funkcja powinna być uniwersalna i działać dla dowolnego tekstu.
//
//void zamien(char *tekst){}
//char tekst[]="Jestem mezrtsim C";
//int main()
//{
//  zamien(tekst);
//  printf("%s\n",tekst);
//  return 0;
//}

void zamien(char *tekst) {
    int start = 0, end = 0, i = 0;
    while (tekst[i] != '\0') {
        if (tekst[i]==' ') {
            if (start==0) {
                start = i;
            } else {
                end = i;
            }
        }
        i++;
    }
    start++; end--;
    int dlugosc = end - start + 1;
    printf("\nstart: %d\nend: %d\n", start, end);
    printf("%c/%c\n", tekst[start], tekst[end]);
    char* temp = malloc(sizeof(char) * (dlugosc));
    for (i=0; i<end-start+1; i++) {
        temp[i] = tekst[end-i];
    }

    for (int i=start; i<=end; i++) {
        tekst[i] = temp[i-start];
    }
}


int main() {
    char tekst[] = "Jestem awruk C";
    zamien(tekst);
    printf("%s\n", tekst);
    return 0;
}
