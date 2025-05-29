#pragma once
#include <iostream>

struct Element{
    int num;
    Element* next;
};

using namespace std;

class Queue {
private:
  Element* head;
  Element* tail;

public:
    Queue() : head(nullptr), tail(nullptr){};

    Element* first() {
        return this->head;
    };

    bool isEmpty() {
        return this->head==nullptr && this->tail == nullptr;
    };

    void push(int value) {
        Element* el = new Element(value, nullptr);

        if (this->isEmpty()) {
            this->head = el;
        }else {
            this->tail->next = el;
        }
        this->tail = el;

    };

    void pop() {
        if (this->isEmpty()) {
            cout << "Kolejka jest pusta" << endl;
            return;
        } else if (this->head == this->tail) {

            this->tail = nullptr;
            this->head = nullptr;
        } else {
            Element* temp = this->head->next;
            this->head = temp;
        }
    };

    // ~Queue();
};
