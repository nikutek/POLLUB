#include <iostream>
#include "Empty.h"

using namespace std;

Empty::Empty()
    : Organism(0,0,'_', true, 0, 0, 0, 0, 0, 0, 0) {}

void Empty::reproduce() {
    cout << "Reproduce empty !!!" << endl;
}

void Empty::eat() {
    cout << "Eat empty !!!" << endl;
}


