//
// Created by student on 12.03.2025.
//

#ifndef RACHUNEK_H
#define RACHUNEK_H
#include <string>

using namespace std;

class Rachunek {
private:
    string firstName;
    string lastName;
    int accountNumber;
    int saldo;

    public:
    Rachunek(string firstName, string lastName, int accountNumber, int saldo);
    ~Rachunek();
    void add(int amount);
    void withdraw(int amount);
    int getSaldo();
    void show();
    void setName(string imie);
    void setLastName(string nazwisko);


};



#endif //RACHUNEK_H
