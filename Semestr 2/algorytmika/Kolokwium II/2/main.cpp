#include <iostream>

struct stos {
    int value;
    stos *next;
};

void push(stos *&w, int x){};

int pop(stos *&w){};

int isEmpty(stos *w){};

int first(stos *w){};

int zad1(stos *w) {
    int even = 0;
    stos *temp = nullptr;
    while (!isEmpty(w)) {
        int value = pop(w);
        push(temp, value);
        if (value % 2 == 0) {
            even++;
        }
    }

    while (!isEmpty(temp)) {
        push(w, pop(temp));
    }
    return even;
}

// ZADANIE 2

struct element {
    int value;
    element* next;
};

int maxEl(element* el, int& czyNiePusta) {
    if (el==nullptr) {
        return 0;
    }
    czyNiePusta = 1;
    int max = el->value;
    element* start = el;
    do {
        if (el->value > max) {
            max = el->value;
        }
        el = el->next;
    } while (el!=start);
    return max;
}

void dodajEl(element*& el, int value) {
    element* nowy = new element();
    nowy->value = value;

    if (el == nullptr) {
        nowy->next = nowy;
        el = nowy;
    } else {
        nowy->next = el->next;
        el->next = nowy;
        el = nowy;
    }
}



int main() {

    element* el = nullptr;
    int czyPusta = 0;
    dodajEl(el, 1);
    dodajEl(el, 2);
    dodajEl(el, 3);
    dodajEl(el, 4);

    std::cout << maxEl(el, czyPusta) << std::endl;


    return 0;
}
