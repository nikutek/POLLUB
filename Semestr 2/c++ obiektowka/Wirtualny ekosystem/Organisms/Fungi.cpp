#include "Fungi.h"
#include <iostream>

int fungiMaxAgeTop = 50;
int fungiMaxAgeBottom = 10;
int fungiCostOfReproduction = 5;

// Constructor Implementation
Fungi::Fungi()
    : Organism('#', true, 1, 10, 0,
               rand() % (fungiMaxAgeTop - fungiMaxAgeBottom + 1) + fungiMaxAgeBottom,
               fungiMaxAgeBottom,
               fungiMaxAgeTop,
               fungiCostOfReproduction) {}

// Function Implementations
void Fungi::reproduce() {
    std::cout << "Fungi cpp reproduced" << std::endl;
}

void Fungi::eat() {
    std::cout << "Fungi cpp eating" << std::endl;
}
