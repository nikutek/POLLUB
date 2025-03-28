#include <iostream>
#include "Bacteria.h"

#include "Empty.h"
#include "../Ecosystem.h"

using namespace std;

int bacteriaMaxAgeTop = 50;
int bacteriaMaxAgeBottom = 10;
int bacteriaCostOfReproduction = 5;

Bacteria::Bacteria()
    : Organism(0, 0, '@', true, 0, 10, 0,
               rand() % (bacteriaMaxAgeTop - bacteriaMaxAgeBottom + 1) + bacteriaMaxAgeBottom, bacteriaMaxAgeBottom,
               bacteriaMaxAgeTop, 5) {
}



void Bacteria::eat() {
    //     Bakteria natomiast poluje. W pierwszej kolejności
    // szuka w swoim sąsiedztwie glonów i jeżeli takie są wybiera losowo jednego. Jeżeli nie ma
    // glonów to szuka innej bakterii. Organizm upolowany jest wchłonięty i znika z ekosystemu
    Organism* randomisedAlgae = getRandomNeighbourOfType('*');
    if (randomisedAlgae) {
        cout << "Bacteria eating algae" << endl;
        this->fullness++;
        Ecosystem::set(randomisedAlgae->getX(), randomisedAlgae->getY(), new Empty);
    } else {
        Organism* randomisedBacteria = getRandomNeighbourOfType('@');
        if (randomisedBacteria) {
            cout << "Bacteria eating other bacteria" << endl;
            this->fullness++;
            Ecosystem::set(randomisedBacteria->getX(), randomisedBacteria->getY(), new Empty);
        }
    }
}
