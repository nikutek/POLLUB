// #ifndef ALGAE_H
// #define ALGAE_H
//
// #include <fstream>
// #include <iostream>
// #include <vector>
// #include "Organism.h"
//
// using namespace std;
//
// class Algae : public Organism {
// public:
//     Algae() : Organism(){
//         this->symbol = '#';
//         this->isAlive = true;
//         this-> fullness = 0;
//         this->eatLimit = 3;
//         this->age = rand()%(config.algae.maxAgeUpperLimit - config.algae.maxAgeLowerLimit) + config.algae.maxAgeLowerLimit,
//         this->maxAge = 5;
//         this->costOfReproduction = 0;
//     }
//
//     void reproduce() override {
//         cout << "Algae reproduced" << endl;
//     }
//
//     void eat() override {
//         cout << "Algae eating" << endl;
//     }
// };
//
// #endif // ALGAE_H
