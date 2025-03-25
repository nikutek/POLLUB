//
// Created by user on 25-Mar-25.
//

#ifndef ALGAE_H
#define ALGAE_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Organism.h"

using namespace std;

class Algae : public Organism{
public:
    Algae() : Organism(){
        this->symbol = "*";
        this->isAlive = true;
        this-> fullness = 0;
        this->eatLimit = 3;
        this->age = 0;
        this->maxAge = 5;
        this->maxAgeLowerLimit = 5;
        this->maxAgeUpperLimit = 5;
        this->costOfReproduction = 0;
    }

    void reproduce() override{
      cout << "algae reproduced" << endl;
    };

    void eat() override{
      cout << "algae eating" << endl;
    }

}
#endif //ALGAE_H
