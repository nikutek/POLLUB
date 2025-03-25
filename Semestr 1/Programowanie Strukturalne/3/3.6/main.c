#include <stdio.h>

int main(void) {
    float kilometry, mile, km, kmh, farenheit;
    printf("Podaj: kilometry, mile, konie mechaniczne, km/h, stopnie farenheita\n");
    scanf("%f, %f, %f, %f, %f", &kilometry, &mile, &km, &kmh,  &farenheit);
    printf("%f kilometry = %f mile\n", kilometry, mile);
    printf("%f mile = %f kilometry\n", mile, kilometry);
    printf("%f koni mechanicznych = %f watów\n", km, km*735);
    printf("%f km/h = %f m/s\n", kmh, kmh*0.28);
    printf("%f stopni Farenheita = %f stopni Celcjusza\n", farenheit, 5/9*(farenheit-32));
    return 0;
}
