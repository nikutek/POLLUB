#include <iostream>
#include "Lista.cpp"

using namespace std;

struct El {
    int value;
    El *next;
    El *prev;
};

class ListaDwukierunkowa {
private:
    El *head;
    El *tail;

public:
    ListaDwukierunkowa() {
        this->head = nullptr;
        this->tail = nullptr;
    };

    bool isEmpty() {
        return this->head == nullptr && this->tail == nullptr;
    }

    El *first() {
        return this->head;
    }

    El *last() {
        return this->tail;
    }

    void show() {
        if (isEmpty()) {
            cout << "Lista jest pusta" << endl;
            return;
        } else if (this->head == this->tail) {
            cout << this->head->value << endl;
        } else {
            El *temp = this->head;
            while (temp->next != nullptr) {
                cout << temp->value << ", ";
                temp = temp->next;
            }
            cout << temp->value << endl;
        }
    };

    int size() {
        if (this->tail == nullptr) {
            return 0;
        }
        int i = 1;
        El *temp = this->head;
        while (temp->next != nullptr) {
            temp = temp->next;
            i++;
        }
        return i;
    }

    void addHead(int value) {
        if (isEmpty()) {
            El *el = new El(value, nullptr, nullptr);
            this->head = el;
            this->tail = el;
        } else {
            El *el = new El(value, this->head, nullptr);
            this->head = el;
            el->next->prev = el;
        }
    }

    void addTail(int value) {
        if (isEmpty()) {
            El *el = new El(value, nullptr, nullptr);
            this->head = el;
            this->tail = el;
        } else {
            El *el = new El(value, nullptr, this->tail);
            this->tail->next = el;
            this->tail = el;
        }
    }


    void addPosition(int value, int position) {
        if (position == 0) {
            addHead(value);
            return;
        } else if (position == this->size()) {
            addTail(value);
        } else if (position > 0 && position < size()) {
            El *temp = this->head;
            for (int i = 0; i < position; i++) {
                temp = temp->next;
            }
            El *el = new El(value, temp, temp->prev);
            temp->prev->next = el;
            el->next->prev = el;
        }
    };

    void deleteHead() {
        if (isEmpty()) {
            cout << "Lista pusta" << endl;
            return;
        }
        if (this->head == this->tail) {
            this->head = this->tail = nullptr;
            return;
        }
        this->head = this->head->next;
        this->head->prev = nullptr;
    };

    void deleteTail() {
        if (this->isEmpty()) {
            cout << "Lista pusta" << endl;
            return;
        } else if (this->head == this->tail) {
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            this->tail->prev->next = nullptr;
            this->tail = this->tail->prev;
        }
    };

    void deletePosition(int position) {
        if (isEmpty()) {
            cout << "Lista jest pusta" << endl;
            return;
        } else if (position == 0) {
            deleteHead();
            return;
        } else if (position == this->size()-1) {
            deleteTail();
            return;
        } else if (position > 0 && position < size()) {
            El* temp = this->head;
            for (int i=0; i<position; i++) {
                temp = temp->next;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    };


    ~ListaDwukierunkowa() {
    };
};
