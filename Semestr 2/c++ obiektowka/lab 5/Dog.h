//
// Created by user on 07-May-25.
//
#include "Animal.h"

#ifndef DOG_H
#define DOG_H

using namespace std;

class Dog : public Animal{
private:
  bool isHealthy;
  public:
    Dog(string name, string breed, int age, bool healthy);
    void bark();
};



#endif //DOG_H
