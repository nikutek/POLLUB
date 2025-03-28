#ifndef FUNGI_H
#define FUNGI_H

#include "Organism.h"


class Fungi : public Organism {
public:
    Fungi();


    void eat() override;
};

#endif // FUNGI_H
