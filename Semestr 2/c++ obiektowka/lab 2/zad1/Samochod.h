//
// Created by student on 12.03.2025.
//

#ifndef PROSTOKAT_H
#define PROSTOKAT_H
#include <string>

using namespace std;

class Samochod {
private:
    string marka;
    string model;
    int rocznik;
    int przebieg;

public:
    Samochod(string="Fiat", string="126", int rocznik=0, int przebieg=0);
    ~Samochod();
    void wczytaj();
    void wypisz();



};



#endif //PROSTOKAT_H
