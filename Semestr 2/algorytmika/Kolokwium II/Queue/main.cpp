#include <iostream>
#include "Queue.cpp"




int main() {

    Queue kolejka;

    cout << kolejka.isEmpty() << endl;
    kolejka.pop();
    kolejka.push(1);
    kolejka.pop();
    kolejka.push(2);
    kolejka.push(3);
    kolejka.pop();
    return 0;
}