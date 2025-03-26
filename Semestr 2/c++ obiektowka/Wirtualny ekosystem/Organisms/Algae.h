//
// Created by user on 26-Mar-25.
//


#include "Organism.h"

class Algae : public Organism {
  public:
    Algae();

    void reproduce() override;
    void eat() override;
};



