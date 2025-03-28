//
// Created by user on 25-Mar-25.
//

#ifndef ORGANISM_H
#define ORGANISM_H
#include <vector>

using namespace std;

class Organism {
protected:
    int x, y;
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

    Organism(int x, int y, char symbol, bool isAlive, int fullness, int eatLimit, int age, int maxAge, int maxAgeLowerLimit,
             int maxAgeUpperLimit, int costOfReproduction);

    bool isHungry();

    virtual void reproduce();

    virtual void eat();

    bool ageGrow();

    bool getIsAlive();

    int getFullness();

    int getAge();

    void show();

    char getSymbol();

    void setPosition(int x, int y); // New setter function

    int getX();
    int getY();

    vector<Organism*> getNeighbours();

    Organism* getRandomNeighbourOfType(char symbol);

    void move();

    int getCostOfReproduction() const {
        return costOfReproduction;
    }
};


#endif //ORGANISM_H
