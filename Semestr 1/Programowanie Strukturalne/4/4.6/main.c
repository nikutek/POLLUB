#include <stdio.h>

float kmToMiles(float km) {
    return km * 0.62;
}
float milesToKm(float miles) {
    return miles * 1.609;
}

float hpToWatts(float hp) {
    return hp * 735;
}

float kmhToMs(float kmh) {
    return kmh * 0.28;
}

float fahrenheitToCelcius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main(void) {
    float kilometry, mile, km, kmh, farenheit;
    printf("Podaj: kilometry, mile, konie mechaniczne, km/h, stopnie farenheita\n");
    scanf("%f, %f, %f, %f, %f", &kilometry, &mile, &km, &kmh,  &farenheit);
    printf("%f kilometry = %f mile\n", kilometry, kmToMiles(kilometry));
    printf("%f mile = %f kilometry\n", mile, milesToKm(mile));
    printf("%f koni mechanicznych = %f watow\n", km, hpToWatts(km));
    printf("%f km/h = %f m/s\n", kmh, kmhToMs(kmh));
    printf("%f stopni Farenheita = %f stopni Celcjusza\n", farenheit, fahrenheitToCelcius(farenheit));
    return 0;
}