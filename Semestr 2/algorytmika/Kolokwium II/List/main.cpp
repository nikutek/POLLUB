#include <iostream>
#include "Lista.cpp"
#include "ListaJednokierunkowa.cpp"

int main() {

    ListaJednokierunkowa list;
    list.show();
    list.addHead(1);
    list.addHead(2);
    list.addHead(3);
    list.addTail(0);
    list.addPosition(8,0);
    list.deleteTail();
    list.show();
    list.deletePosition(1);
    list.show();
    return 0;
}