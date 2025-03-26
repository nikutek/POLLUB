//
// Created by user on 26-Mar-25.
//

#ifndef BACTERIA_H
#define BACTERIA_H

#include "Organism.h"

class Bacteria : public Organism{
  public:
    Bacteria();

    void reproduce() override;

    void eat() override;

};



#endif //BACTERIA_H
