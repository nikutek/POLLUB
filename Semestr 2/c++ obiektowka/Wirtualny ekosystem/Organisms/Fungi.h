#ifndef FUNGI_H
#define FUNGI_H

#include "Organism.h"
#include <iostream>

class Fungi : public Organism {
public:
    Fungi(const Config& config) : Organism() {
        this->symbol = '#';
        this->isAlive = true;
        this->fullness = 0;
        this->eatLimit = config.fungi.eatLimit;
        this->age = 0;
        this->maxAge = 5;
        this->costOfReproduction = config.fungi.costOfReproduction;
    }

    void reproduce() override {
        std::cout << "Fungi reproduced" << std::endl;
    }

    void eat() override {
        std::cout << "Fungi eating" << std::endl;
    }
};

#endif // FUNGI_H
