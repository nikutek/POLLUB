#include <iostream>

#include "Rachunek.h"

void changeOwner(Rachunek rachunek) {
    string imie, nazwisko;
    cout << "Wybierz imie: ";
    cin >> imie;
    cout << "Wybierz nazwisko: ";
    cin >> nazwisko;

    rachunek.setName(imie);
    rachunek.setLastName(nazwisko);
}

int main() {
    //Statyczna tablica obiektów dynamicznych
    Rachunek *statDyn[3];
    for (int i = 0; i < 3; i++) {
        statDyn[i] = new Rachunek("Imie", "Nazwisko", i*11, i*100);
    }
    for (int i = 0; i < 3; i++) {
        statDyn[i]->show();
    }
    for (int i = 0; i < 3; i++) {
        delete statDyn[i];
    }

    //Statyczna tablica obiektów statychnych
    Rachunek statStat[2] = {Rachunek("maciek","Solid",123, 1000), Rachunek("Daniel", "naziwsko", 321, 2000)};
    for (int i = 0; i < 2; i++) {
        statStat[i].show();
    }

//    Dynamiczna tablica dynamicznych obiektów
    Rachunek **dynDyn = new Rachunek*[3];
    for (int i = 0; i < 3; i++) {
      dynDyn[i] = new Rachunek("Imie", "Nazwisko", i*11, i*100);
    }
    for (int i = 0; i < 3; i++) {
      dynDyn[i]->show();
    }

    for (int i = 0; i < 3; i++) {
      delete dynDyn[i];
    }

//    Dynamiczna tablica statycznych obiektów
    Rachunek *dynStat[3];
    for (int i = 0; i < 3; i++) {
      dynStat[i] = new Rachunek("Maciek", "Solid", i*11, i*100);
    }
    for (int i = 0; i < 3; i++) {
      dynStat[i]->show();
    }

}
