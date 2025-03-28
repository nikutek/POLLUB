#ifndef ALGAE_H
#define ALGAE_H

#include <iostream>
#include "Algae.h"

int algaeMaxAgeTop = 10;
int algaeMaxAgeBottom = 5;
int algaeCostOfReproduction = 5;

using namespace std;

Algae::Algae()
    : Organism(0,0,'*', true, 0, 10, 0,
               rand() % (algaeMaxAgeTop - algaeMaxAgeBottom + 1) + algaeMaxAgeBottom, // Random maxAge
               algaeMaxAgeBottom,
               algaeMaxAgeTop,
               algaeCostOfReproduction) {}



void Algae::eat() {
    this->fullness++;
}



#endif // ALGAE_H
