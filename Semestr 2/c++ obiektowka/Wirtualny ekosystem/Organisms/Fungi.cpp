//
// Created by user on 25-Mar-25.
//

//TODO: Naprawić konstruktor i header

#ifndef FUNGI_H
#define FUNGI_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Organism.h"

using namespace std;

class Fungi : public Organism{
public:
    Fungi() : Organism(){
        cout << "Fungi " << config.fungi.maxAgeLowerLimit << config.fungi.maxAgeUpperLimit << endl;
        this->symbol = '#';
        this->isAlive = true;
        this-> fullness = 0;
        this->eatLimit = 3;
        this->age = rand()%(config.fungi.maxAgeUpperLimit - config.fungi.maxAgeLowerLimit) + config.fungi.maxAgeLowerLimit,
        this->maxAge = 5;
        this->costOfReproduction = 0;
    }

    void reproduce() override{
        cout << "algae reproduced" << endl;
    };

    void eat() override{
        cout << "algae eating" << endl;
    }

};
#endif
