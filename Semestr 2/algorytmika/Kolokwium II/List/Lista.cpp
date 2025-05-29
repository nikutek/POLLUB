#pragma once
#include <iostream>

using namespace std;

struct Element{
    int value;
    Element* next;
};

class Lista {
protected:
  Element* head;
  Element* tail;

public:
    Lista() {
      this->head = nullptr;
      this->tail = nullptr;
    };

    virtual void addHead(int value)=0;
    virtual void addTail(int value)=0;
    virtual void addPosition(int value, int position)=0;

    virtual void deleteHead()=0;
    virtual void deleteTail()=0;
    virtual void deletePosition(int position)=0;

    void show(){
        if (this->head == nullptr && this->tail == nullptr) {
            cout << "Lista jest pusta" << endl;
            return;
        }
        Element* el = this->head;
        while (el->next != nullptr) {
            cout << el->value << ", ";
            el = el->next;
        }
        cout << this->tail->value << endl;
    };
    Element* first() {
        return this->head;
    };
    Element* last() {
        return this->tail;
    };
    bool isEmpty() {
        return this->head == nullptr && this->tail == nullptr;
    }

  ~Lista(){};

};
