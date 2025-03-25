#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


struct Student {
public:
    string imie;
    string nazwisko;
    int pkt;

    void toString() {
        cout << imie << " " << nazwisko << " " << pkt << endl;
    }
};

void wczytajStudentow(Student*& tab, int &n) {
    string linia, temp;
    ifstream plik;
    int liczbaStudentow;
    stringstream ss;

    plik.open("../studenci.csv");
    if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc pliku";
        return;
    }

    plik >> liczbaStudentow;
    n=liczbaStudentow;
    tab = new Student[liczbaStudentow];
    getline(plik, linia);

    for (int i=0; i<liczbaStudentow; i++) {
        getline(plik, linia);
        if (linia.length()==0) return;

        stringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, temp);
        tab[i].pkt = atoi(temp.c_str());
    }
    plik.close();
}

void wyswietlStudentow(Student*& tab, int n){
    for (int i=0; i< n; i++){
        cout << tab[i].imie <<" "<< tab[i].nazwisko <<" " << tab[i].pkt << endl;
    }
}

int podzialNaDwieCzesci(Student*& tab, int n) {
    int i=0;
    int j = n-1;

    while (i<j) {
        while (tab[i].pkt<=10 && i<j) i++;
        while(tab[j].pkt > 10 && i<j) j--;

        if (i<j) {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }
    if (tab[i].pkt<=10) {
        return i+1;
    }
    return i;


}

void podzialNaTrzyCzesci(Student*& tab, int n, int& ii, int& jj) {
    int i = -1;  // Granica dla pkt%3==0
    int j = 0;   // Bieżący indeks
    int k = n;   // Granica dla pkt%3==2

    while (j < k) {
        if (tab[j].pkt % 3 == 0) {  // pkt % 3 == 0 -> na początek
            i++;
            swap(tab[i], tab[j]);
            j++;
        }
        else if (tab[j].pkt % 3 == 2) {  // pkt % 3 == 2 -> na koniec
            k--;
            swap(tab[k], tab[j]);
        }
        else {  // pkt % 3 == 1 -> zostaje w środku
            j++;
        }
    }
    cout << "i: " << i << "\tj:" << j << endl;
    ii = i;
    jj=j;

}

int main() {
    Student* tab;
    int n;
    wczytajStudentow(tab, n);
    wyswietlStudentow(tab, n);
    cout << endl << "Po podziale na 2 czesci: " << endl;
    podzialNaDwieCzesci(tab, n);
    wyswietlStudentow(tab, n);

    cout << "---------------------------------------------------------------------" << endl;


    int i,j;
    wczytajStudentow(tab, n);
    podzialNaTrzyCzesci(tab, n, i, j);

    cout << "Studenci, którzy otrzymali liczbę punktów podzielnych przez 3:" << endl;
    for (int a = 0; a <= i; a++) {
        tab[a].toString();
    }
    cout << "Studenci, którzy otrzymali liczbę punktów podzielnych przez 3 z resztą 1:" << endl;
    for (int a=i; a<=j; a++) {
        tab[a].toString();
    }
    cout << "Studenci, którzy otrzymali liczbę punktów podzielnych przez 3 z resztą 2:" << endl;
    for (int a=j; a<=n; a++) {
        tab[a].toString();
    }

    return 0;
}
