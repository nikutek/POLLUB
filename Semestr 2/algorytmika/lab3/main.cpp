#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Student{
    public:
        string imie;
        string nazwisko;
        int pkt;
};

void wczytajStudentow(Student*& tab, int &n){
    string linia, pomoc;
    ifstream plik;
    int liczbaStudentow;
    char sredniki;
    stringstream ss;

    plik.open("../studenci.csv");
    if(!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku." << endl;
        return;
    }
    plik >> liczbaStudentow;
    n=liczbaStudentow;
    cout << liczbaStudentow << endl;

    tab = new Student[liczbaStudentow];
    getline(plik, linia);

    for (int i=0; i<liczbaStudentow; i++){
        if (!getline(plik, linia)) break;

        stringstream ss(linia);
        getline(ss,tab[i].imie,';');
        getline(ss,tab[i].nazwisko,';');
        getline(ss, pomoc);
        tab[i].pkt = atoi(pomoc.c_str());
    }
    plik.close();
}

void wyswietlStudentow(Student*& tab, int n){
    cout << "------------------------------------------"<< endl;
    for (int i=0; i< n; i++){
        cout << tab[i].imie <<" "<< tab[i].nazwisko <<" " << tab[i].pkt << endl;
    }
}

void sortowanieQuickSort(Student* tab, int lewy, int prawy, int tryb) {
    if (prawy <= lewy) return;

    int i = lewy-1;
    int j = prawy+1;
    int pivot = tab[(lewy+prawy)/2].pkt;

    while (1) {
        while (pivot > tab[++i].pkt);
        while (pivot < tab[--j].pkt);

        if (i<=j) {
            swap(tab[i], tab[j]);
        } else {
            break;
        }
    }

    if ( j > lewy) {
        sortowanieQuickSort(tab, lewy, j, tryb);
    }
    if (i < prawy) {
        sortowanieQuickSort(tab, i, prawy, tryb);
    }


}

int main() {
    Student* studenci=nullptr;
    int n=0;
    wczytajStudentow(studenci, n);
    wyswietlStudentow(studenci, n);
    sortowanieQuickSort(studenci, 0, n-1, 1);
    wyswietlStudentow(studenci, n);
    return 0;
}
