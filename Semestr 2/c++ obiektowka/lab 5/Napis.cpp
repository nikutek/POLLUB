
#include<iostream>
#include "Napis.h"

#include <algorithm>
#include <set>
#include <string.h>
#include <vector>
#include <bits/ranges_algo.h>

using namespace std;

Napis::Napis() : napis(""){}

Napis::Napis(string n) : napis(n){}

void Napis::setNapis(string n) {
    this->napis = n;
}

string Napis::getNapis() {
    return this-> napis;
}

int Napis::getsize() {
    return this->napis.size();
}

void Napis::show() {
    cout << this->napis << endl;
}

int Napis::ileSamoglowek() {
    int ile = 0;
    for (char c : this->napis) {
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') ile++;
    }
    return ile;
}

bool Napis::anagram(string string2) {
    vector<char> n1(this->napis.begin(), this->napis.end());
    vector<char> n2(string2.begin(), string2.end());
    if (this->napis.size() != string2.size()) return false;
    for (char c : n1) {
        bool found = false;
        int at;
        for (int i=0 ; i < n2.size() ; i++) {
            if (c == n2[i]) {
                found = true;
                at =i;
                n2.erase(n2.begin()+at);
                break;
            }
        }
        if (!found) return false;
    }
    return n2.size()==0;
}

void Napis::maleDuze() {
    int male=0;
    int duze=0;
    for (char c : this->napis) {
        if (std::islower(c)) male++;
        else if (std::isupper(c)) duze++;
    }
    cout << "Male: " << male << endl;
    cout << "Duze: " << duze << endl;
}
