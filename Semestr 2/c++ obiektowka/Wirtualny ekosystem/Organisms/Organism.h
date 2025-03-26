//
// Created by user on 25-Mar-25.
//

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
    virtual ~Organism() = default;

    Organism();

    Organism(char symbol, bool isAlive, int fullness, int eatLimit, int age, int maxAge, int maxAgeLowerLimit,
             int maxAgeUpperLimit, int costOfReproduction);

    bool isHungry();

    virtual void reproduce();

    virtual void eat();

    bool getIsAlive();

    int getFullness();

    int getAge();

    void show();

    char getSymbol();
};


#endif //ORGANISM_H
