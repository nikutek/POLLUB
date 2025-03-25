#include <stdio.h>

void kwartal(int miesiac){
  if (miesiac>0 && miesiac<=3){
    printf("kwartal 1");
   } else if (miesiac>3 && miesiac<=6){
     printf("kwartal 2");
   } else if (miesiac>6 && miesiac<=9){
     printf("kwartal 3");
   } else if (miesiac>9 && miesiac<=12){
     printf("kwartal 4");
   } else {
     printf("Nieprawidłowy miesiac");
   }

   if(miesiac==2){
     printf("\n 28 lub 29 dni");
   } else if(miesiac%2==0){
     printf("\n 31 dni");
   } else if(miesiac%2==1){
     printf("\n 30 dni")
   }
}

int main(void) {
    printf("Hello, World!\n");
    kwatal(3);
    return 0;

}
