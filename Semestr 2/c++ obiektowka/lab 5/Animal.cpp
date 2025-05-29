
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Animal.h"

using namespace std;

Animal::Animal(string name, string breed, int age) {
    this->name = name;
    this->breed = breed;
    this->age = age;
}

void Animal::eat() {
    cout << this->name << endl;
}

