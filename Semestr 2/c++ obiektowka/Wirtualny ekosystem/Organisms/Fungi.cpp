#include "Fungi.h"
#include <iostream>
#include <vector>

#include "Empty.h"
#include "../Ecosystem.h"

using namespace std;

int fungiMaxAgeTop = 50;
int fungiMaxAgeBottom = 10;
int fungiCostOfReproduction = 5;

// Constructor Implementation
Fungi::Fungi()
    : Organism(0,0,'#', true, 1, 10, 0,
               rand() % (fungiMaxAgeTop - fungiMaxAgeBottom + 1) + fungiMaxAgeBottom,
               fungiMaxAgeBottom,
               fungiMaxAgeTop,
               fungiCostOfReproduction) {}

// Function Implementations
void Fungi::reproduce() {
    std::cout << "Fungi cpp reproduced" << std::endl;
}

void Fungi::eat() {
//     Grzyb szuka w swoim sąsiedztwie
// organizmów martwych i jeżeli takie są to losowo wybiera jeden z nich i go wchłania.
// Organizm wchłonięty znika z ekosystemu.

    vector<Organism*> neighbours = getNeighbours();
    bool hasDeadNeighbour=false;
     for (Organism* neighbour : neighbours) {
         cout << neighbour->getSymbol();
         if (neighbour->getSymbol() == '+') hasDeadNeighbour = true;
     }

    if (hasDeadNeighbour) {
        Organism* randomisedNeighbour = neighbours.at(rand() % neighbours.size());
        while (randomisedNeighbour->getSymbol()!='+') {
            randomisedNeighbour = neighbours.at(rand() % neighbours.size());
        }

        Ecosystem::set(randomisedNeighbour->getX(), randomisedNeighbour->getY(), new Empty);
        this->fullness++;
    }
}
