#include <stdio.h>
#include <stdlib.h>
#include "Dog.h"


Dog::Dog(string name, string breed, int age, bool healthy) : Animal(name, breed, age) {
    healthy = healthy;
}

