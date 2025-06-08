#include <iostream>

using namespace std;

struct kolejka {
};

void attach(kolejka *&k, int x) {
}

int detach(kolejka *&k) {
};

int isEmpty(kolejka *k) {
};

int first(kolejka *k) {
};

int zad1(kolejka *k) {
    if (k == nullptr) return 0;
    kolejka *temp = nullptr;
    int counter = 0;
    while (!isEmpty(k)) {
        int value = detach(k);
        if (value % 3 == 0) {
            counter++;
        }
        attach(temp, value);
    }

    while (!isEmpty(temp)) {
        attach(k, detach(temp));
    }

    return counter;
}

// ZADANIE 2

struct element {
    int value;
    element* prev;
    element* next;
};

int min(element*& start, int& czyPusta) {
    if (start==nullptr) {
        czyPusta = 1;
        return 0;
    }
    czyPusta = 0;

    element* el = start->next;
    int min=start->value;

    while (el != start) {
        if (el->value < min) {
            min = el->value;
        }
        el = el->next;
    }
    return min;
}

int main() {
    return 0;
}
