//
// Created by user on 12-Mar-25.
//

#include "Osoba.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;

Osoba::Osoba(string imie, char plec, bool status, int wiek){
  this->imie = imie;
  this->plec = plec;
  this->status = status;
  this->wiek = wiek;
  }

 Osoba::~Osoba(){
    cout << "Destruktor" << std::endl;
  }

string Osoba::getImie(){
    return this->imie;
    }
    char Osoba::getPlec(){
      return this->plec;
    }
    bool Osoba::getStatus(){
      return this->status;
    }
    int Osoba::getWiek(){
      return this->wiek;
    }
    void Osoba::setImie(string imie){
      this->imie = imie;
    }
    void Osoba::setPlec(char plec){
      this->plec = plec;
    }
    void Osoba::setStatus(bool status){
      this->status = status;
    }
    void Osoba::setWiek(int wiek){
      this->wiek = wiek;
    }
    string Osoba::toString(){
      stringstream ss;
      ss << this->imie << this->plec << this->status << this->wiek;
      return ss.str();
    }
