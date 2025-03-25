#ifndef ORGANISM_H
#define ORGANISM_H

class Organism {
protected:
    char symbol;
    bool isAlive;
    int fullness;
    int eatLimit;
    int age;
    int maxAge;
    int maxAgeLowerLimit;
    int maxAgeUpperLimit;
    int costOfReproduction;

public:
    Organism() : symbol('?'), isAlive(true), fullness(0), eatLimit(5), age(0),
                maxAge(100), maxAgeLowerLimit(50), maxAgeUpperLimit(150), costOfReproduction(10) {}

    Organism(char symbol, bool isAlive, int fullness, int eatLimit, int age,
             int maxAge, int maxAgeLowerLimit, int maxAgeUpperLimit, int costOfReproduction)
        : symbol(symbol), isAlive(isAlive), fullness(fullness), eatLimit(eatLimit),
          age(age), maxAge(maxAge), maxAgeLowerLimit(maxAgeLowerLimit),
          maxAgeUpperLimit(maxAgeUpperLimit), costOfReproduction(costOfReproduction) {}

    virtual void reproduce() = 0;
    virtual void eat() = 0;

    bool isHungry() {
        return this->fullness < this->eatLimit;
    }

    bool getIsAlive() const {
        return this->isAlive;
    }

    int getFullness() const {
        return this->fullness;
    }

    int getAge() const {
        return this->age;
    }

    virtual ~Organism() {}
};

#endif
