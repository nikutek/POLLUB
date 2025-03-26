#ifndef ALGAE_H
#define ALGAE_H

#include <iostream>
#include "Algae.h"

int algaeMaxAgeTop = 50;
int algaeMaxAgeBottom = 10;
int algaeCostOfReproduction = 5;

using namespace std;

Algae::Algae()
    : Organism('*', true, 0, 10, 0,
               rand() % (algaeMaxAgeTop - algaeMaxAgeBottom + 1) + algaeMaxAgeBottom, // Random maxAge
               algaeMaxAgeBottom,
               algaeMaxAgeTop,
               algaeCostOfReproduction) {}

void Algae::reproduce() {
    cout << "Algae::reproduce()" << endl;
}

void Algae::eat() {
    cout << "Algae::eat()" << endl;
}



#endif // ALGAE_H
