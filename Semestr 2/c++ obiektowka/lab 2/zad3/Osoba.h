//
// Created by user on 12-Mar-25.
//

#ifndef OSOBA_H
#define OSOBA_H
#include <string>

using namespace std;

class Osoba {
private:
  string imie;
  char plec;
  bool status;
  int wiek;

public:
  Osoba(string imie, char plec, bool status, int wiek);
  ~Osoba();
  void setImie(string imie);
  string getImie();
  void setPlec(char plec);
  char getPlec();
  void setStatus(bool status);
  bool getStatus();
  void setWiek(int wiek);
  int getWiek();

  string toString();
};



#endif //OSOBA_H
