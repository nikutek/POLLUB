//
// Created by student on 12.03.2025.
//

#include "Rachunek.h"

#include <iostream>
#include <ostream>

Rachunek::Rachunek(string firstName, string lastName, int accountNumber, int saldo) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->accountNumber = accountNumber;
    this->saldo = saldo;
}

void Rachunek::add(int amount) {
    this->saldo += amount;
}

void Rachunek::withdraw(int amount) {
    this->saldo -= amount;
}

int Rachunek::getSaldo() {
    return this->saldo;
}

void Rachunek::show() {
        cout << this->firstName << " " << this->lastName << " " << this->accountNumber << " " << this->saldo << endl;
}

void Rachunek::setName(string imie) {
    this->firstName = imie;
}

void Rachunek::setLastName(string nazwisko) {
    this->lastName= nazwisko;
}

Rachunek::~Rachunek() {
    cout << "Destructor: ";
    this->show();
}





