//
// Created by user on 07-May-25.
//

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

class Animal {
private:
  string name;
  string breed;
  int age;

  public:
    Animal(string name, string breed, int age);
    void eat();
};



#endif //ANIMAL_H
