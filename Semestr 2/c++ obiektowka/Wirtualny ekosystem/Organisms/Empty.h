//
// Created by user on 26-Mar-25.
//

#ifndef EMPTY_H
#define EMPTY_H

#include "Organism.h"


class Empty : public Organism{
  public:
    Empty();

    void reproduce() override;

    void eat() override;

};



#endif //EMPTY_H
