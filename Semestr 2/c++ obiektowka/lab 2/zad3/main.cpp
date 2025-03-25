#include <iostream>
#include "Osoba.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Osoba osoba1("Jan", 'M', true, 30);
    Osoba osoba2("Anna", 'K', false, 25);

    cout << "Osoba 1: " << osoba1.toString() << endl;
    cout << "Osoba 2: " << osoba2.toString() << endl;

    osoba1.setImie("Krzysztof");
    osoba1.setPlec('M');
    osoba1.setStatus(false);
    osoba1.setWiek(40);

    cout << "\nPo zmianach:" << endl;
    cout << "Osoba 1: " << osoba1.toString() << endl;

    cout << "Imie: " << osoba1.getImie() << endl;
    cout << "Plec: " << osoba1.getPlec() << endl;
    cout << "Status: " << osoba1.getStatus() << endl;
    cout << "Wiek: " << osoba1.getWiek() << endl;

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.