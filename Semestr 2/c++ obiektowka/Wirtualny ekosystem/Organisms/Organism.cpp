#include "Organism.h"

#include <iostream>
#include <ostream>
#include <sstream>

#include "Algae.h"
#include "Bacteria.h"
#include "Fungi.h"
#include "../Ecosystem.h"

using namespace std;
// Default constructor
Organism::Organism()
    : x(0), y(0), symbol('?'), isAlive(true), fullness(0), eatLimit(5), age(0),
      maxAge(100), maxAgeLowerLimit(50), maxAgeUpperLimit(150), costOfReproduction(10) {
}

// Parameterized constructor
Organism::Organism(int x, int y, char symbol, bool isAlive, int fullness, int eatLimit, int age,
                   int maxAge, int maxAgeLowerLimit, int maxAgeUpperLimit, int costOfReproduction)
    : x(x), y(y), symbol(symbol), isAlive(isAlive), fullness(fullness), eatLimit(eatLimit),
      age(age), maxAge(maxAge), maxAgeLowerLimit(maxAgeLowerLimit),
      maxAgeUpperLimit(maxAgeUpperLimit), costOfReproduction(costOfReproduction) {
}

void Organism::reproduce() {
    if (!this->isAlive) return;

    if (this->fullness > this->costOfReproduction) {
        Organism *randomisedCell = getRandomNeighbourOfType('_');

        // Ensure there's an empty space before proceeding
        if (!randomisedCell) return; // No available space, do nothing

        this->fullness -= this->costOfReproduction;

        Organism *newOrganism = nullptr;

        switch (this->getSymbol()) {
            case '*':
                newOrganism = new Algae();
                newOrganism->setPosition(randomisedCell->getX(), randomisedCell->getY());
                break;
            case '#':
                newOrganism = new Fungi();
                newOrganism->setPosition(randomisedCell->getX(), randomisedCell->getY());
                break;
            case '@':
                newOrganism = new Bacteria();
                newOrganism->setPosition(randomisedCell->getX(), randomisedCell->getY());
                break;
        }

        if (newOrganism) {
            newOrganism->setPosition(randomisedCell->getX(), randomisedCell->getY());
            Ecosystem::set(randomisedCell->getX(), randomisedCell->getY(), newOrganism);
            cout << this->getSymbol()<<"(" <<x <<","<<y<<")" << " reproduced at "
                    << randomisedCell->getX() << "," << randomisedCell->getY() << endl;
        }
    }
}


void Organism::eat() {
    std::cout << "Organism eat" << std::endl;
}

bool Organism::ageGrow() {
    this->age++;
    if (this->age > this->maxAge) {
        this->symbol = '+';
    }
    return this->age > maxAge;
}


bool Organism::isHungry() {
    return this->fullness < this->eatLimit;
}

bool Organism::getIsAlive() {
    return this->isAlive;
}

int Organism::getFullness() {
    return this->fullness;
}

int Organism::getAge() {
    return this->age;
}

void Organism::show() {
    stringstream ss;
    ss << "Symbol: " << symbol << "\n";
    ss << "Position: " << x << "," << y << "\n";
    ss << "Alive: " << (isAlive ? "Yes" : "No") << "\n";
    ss << "Fullness: " << fullness << "/" << eatLimit << "\n";
    ss << "Age: " << age << "/" << maxAge << "\n";
    ss << "Reproduction Cost: " << costOfReproduction << "\n";
    cout << ss.str() << endl;
}

char Organism::getSymbol() {
    return this->symbol;
}

void Organism::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

int Organism::getX() { return x; }
int Organism::getY() { return y; }

vector<Organism *> Organism::getNeighbours() {
    return Ecosystem::getNeighbours(x, y);
}

Organism *Organism::getRandomNeighbourOfType(char symbol) {
    vector<Organism *> neighbours = getNeighbours();
    bool contains = false;
    for (Organism *neighbour: neighbours) {
        if (neighbour->getSymbol() == symbol) contains = true;
    }
    if (!contains) return nullptr;

    Organism *randomisedNeighbour = neighbours.at(rand() % neighbours.size());
    while (randomisedNeighbour->getSymbol() != symbol) {
        randomisedNeighbour = neighbours.at(rand() % neighbours.size());
    }
    return randomisedNeighbour;
}


void Organism::move() {
    Ecosystem::moveOrganism(x, y);
}
