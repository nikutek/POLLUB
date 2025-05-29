#include <iostream>

using namespace std;

struct Element {
    int num;
    Element* next;
};

class Stack {
private:
    Element* top;
public:
    Stack() {
        this->top = nullptr;
    }

    bool empty() {
        return this->top == nullptr;
    };

    void push(int value) {
        Element* el = new Element(value, top);
        this->top = el;
    };

    void pop() {
        if (empty()) {
            cout << "Stack empty" << endl;
        } else {
            Element* temp = top;
            this->top = temp->next;
        }
    };

};

int main() {

    Stack stack;
    cout << stack.empty();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    cout << stack.empty();
    return 0;
}