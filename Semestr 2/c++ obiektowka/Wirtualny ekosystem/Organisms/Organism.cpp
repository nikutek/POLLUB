#include "Organism.h"

#include <iostream>
#include <ostream>
#include <sstream>

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
    std::cout << "Organism reproduced" << std::endl;
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

void Organism::move() {
    Ecosystem::moveOrganism(this->x, this->y);
}


