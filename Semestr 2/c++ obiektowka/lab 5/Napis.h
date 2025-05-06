//
// Created by user on 06-May-25.
//

#include<iostream>

#ifndef NAPIS_H
#define NAPIS_H

using namespace std;

class Napis {
private:
  string napis;
  public:
    Napis();
    Napis(string);
    string getNapis();
    void setNapis(string);
    void show();
    int getsize();
    bool anagram(string string2);
    void maleDuze();
    int ileSamoglowek();
};



#endif //NAPIS_H
