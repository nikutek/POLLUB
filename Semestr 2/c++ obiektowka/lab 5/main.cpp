#include <iostream>
#include "Napis.h"
#include "Animal.h"
#include "Dog.h"

int main() {
    Napis napis = Napis();
    napis.setNapis("hj");

    napis.show();
    cout << napis.getsize() << endl;
    napis.ileSamoglowek();
    cout << napis.anagram("juHjh") << endl;
    napis.maleDuze();

    Animal a("kkk", "AAA", 13);
    a.eat();

    Dog d("kolega", "niepamietam", 10, true);
    d.eat();
    return 0;
}