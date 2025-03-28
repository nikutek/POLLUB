#include <iostream>
#include "Bacteria.h"

using namespace std;

int bacteriaMaxAgeTop = 50;
int bacteriaMaxAgeBottom = 10;
int bacteriaCostOfReproduction = 5;

Bacteria::Bacteria()
    : Organism(0,0,'@', true, 0, 10, 0, rand() % (bacteriaMaxAgeTop - bacteriaMaxAgeBottom + 1) + bacteriaMaxAgeBottom, bacteriaMaxAgeBottom, bacteriaMaxAgeTop, 5) {}

void Bacteria::reproduce(){
  cout << "Bacteria reproducing" << endl;
  }

void Bacteria::eat() {
  cout << "Bacteria eating" << endl;
  }