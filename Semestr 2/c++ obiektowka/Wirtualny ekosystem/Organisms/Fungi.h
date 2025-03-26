#ifndef FUNGI_H
#define FUNGI_H

#include "Organism.h"
#include <iostream>
#include <cstdlib>  // For rand()



class Fungi : public Organism {
public:
    Fungi();

    void reproduce() override;
    void eat() override;
};

#endif // FUNGI_H
