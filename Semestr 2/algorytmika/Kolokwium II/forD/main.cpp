#include <iostream>

using namespace std;

struct element {
    int valaue;
    element* next;
    element* prev;
};

void dodaj(int val, element*& lista) { // ważne że przy argumencie musi być *& bo inaczej nie bedzie dzialac
    element* newElement = new element;
    newElement->valaue = val;

    if (lista == nullptr) {
        newElement->next = newElement;
        newElement->prev = newElement;
        lista = newElement; // jak stworzysz ten nowy element to musisz go podmienic w miejsce listy jeśli jest pusta
        return;
    }

    newElement->prev = lista;
    newElement->next = lista->next; // to sobie przekmiń bo to nie jest wcale tak logiczne

    lista->next->prev = newElement; // to ważne żeby nie popierdolić się z kolejnością
    lista->next = newElement;
}

int usun3(element*& start) {
    if (start==nullptr) { // o takich edge case'ach łatwo jest zapomnieć
        cout << "Lista nie jest zainicjowana" << endl;
        return -1;
    }
    element* el = start;
    for (int i=0;i<2;i++) { // idziesz 3 elementy do przodu
        el = el->next;
        if (el == start) { // każdy po drodze sprawdzasz czy nie jest taki sam jak pierwszy bo to by znaczylo ze jest w liscie mniej niz 3 elementy
            cout << "lista ma mniej niż 3 elementy" << endl;
            return -1;
        }

    }

    el->prev->next = el->next; // poprzedni element wskazuje na nastepny wiec tak jakby pomijany jest ten 3
    el->next->prev = el->prev; // vice versa

    int wartosc = el->valaue; //bez tego nie dalo by sie zwrocic potem
    delete el; // ona sie przypierdala akurat jak sie wskaźnika z pamieci nie usunie
    return wartosc; // może nie trzeba by robic tej zmiennej wartosc i jej zwracać ale no chyba sie przyjelo ze funkcje usuwajace zwracaja to co usuwaja
}


void wyswitl(element* start) {
    element* el = start; //kopiujesz ten element od ktorego zaczynasz
    cout << "Zawartosc listy : ";
    do  { // i lecisz dookoła aż na niego znowu nie trafisz, ważne że do while używasz bo inaczej ze zwykłym while'm by sie wcale nie wsykonywało bo warunek z bomby jest spełniony że el = start
        cout << el->valaue << " "; // po drodze printujesz to na czym stoisz
        el = el->next; // i przechodzisz do kolejnego
    } while (start!=el);
    cout <<endl;
}

int main() {
    int wybor;
    element* lista = nullptr;
    while (true) {
        cout << "1. dodaj\n2.usun trzeci\n3.wyswietl"<<endl;
        cin >> wybor;

        switch (wybor) {
            case(1):
                int x;
                cout <<"Podaj wartosc: ";
                cin >> x;
                dodaj(x, lista);
                break;

            case(2):
                usun3(lista);
                break;

            case(3):
                wyswitl(lista);
                break;

            default:
                exit(0);
        }
    }
}
