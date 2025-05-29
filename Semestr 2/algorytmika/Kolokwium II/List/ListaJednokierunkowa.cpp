
#include <iostream>
#include "Lista.cpp"

using namespace std;




class ListaJednokierunkowa : public Lista{
private:

public:
    ListaJednokierunkowa() {
        this->head = nullptr;
        this->tail = nullptr;
    };

    void addHead(int value) override {
        Element* el = new Element(value, this->head);
        if (isEmpty()) {
            this->tail = el;
        }
        this->head = el;

    };
    void addTail(int value) override {
        Element* el = new Element(value, nullptr);
        if (isEmpty()) {
            this->head = el;
        } else {
            this->tail->next = el;
        }
        this->tail = el;
    };

    void addPosition(int value, int position) override {
        if (position==0) {
            addHead(value);
            return;
        }
        Element* el = new Element(value, nullptr);
        Element* tempFront = this->head;
        for (int i=0; i< position; i++) {
            tempFront = tempFront->next;
        }
        Element* tempBack = tempFront-> next;
        if (tempBack==nullptr) {
            this->tail = el;
        }
        tempFront->next = el;
        el->next = tempBack;

    };

    void deleteHead() override {
        if (isEmpty()) {
            cout << "Lista jest pusta" << endl;
        } else if (this->head == this->tail) {
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            this->head = this->head->next;
        }
    };
    void deleteTail() override {
        if (isEmpty()) {
            cout << "Lista jest pusta" << endl;
            return;
        } else if (this->head == this->tail) {
            this->head == nullptr;
            this->tail == nullptr;
        }
        Element* temp = this->head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nullptr;
        this->tail = temp;
        cout << temp->value << endl;

    };
    void deletePosition(int position) override {
        if (isEmpty()) {
            cout << "Lista jest pusta" << endl;
            return;
        } else if (position ==0) {
            this->head = this->head->next;
            return;
        }

        Element* temp = this->head;
        for (int i=0; i<position-1; i++) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            temp->next = nullptr;
            this->tail = temp;
        }
        temp->next = temp->next->next;
    };

};
