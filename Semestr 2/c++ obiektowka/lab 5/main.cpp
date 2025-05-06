#include <iostream>
#include "Napis.h"

int main() {
    Napis napis = Napis();
    napis.setNapis("hHujj");

    napis.show();
    cout << napis.getsize() << endl;
    napis.ileSamoglowek();
    cout << napis.anagram("juHjh") << endl;
    napis.maleDuze();
    return 0;
}