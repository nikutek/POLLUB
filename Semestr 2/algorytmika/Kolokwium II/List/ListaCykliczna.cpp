#pragma once
#include <iostream>

using namespace std;

struct Element {
    int value;
    Element *next;
};


class ListaCykliczna {
private:
    Element* first;
    Element* last;


public:
    ListaCykliczna() {
        this->first = nullptr;
        this->last = nullptr;
    }

    void add(int value) {
        Element* el = new Element(value, this->first);
        if (this->first==nullptr) {
            this->first = el;
            this->last = el;
            el->next = el;
            return;
        }
        this->first = el;

    }

};
