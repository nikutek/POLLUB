#include <iostream>

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int* stworzTablice(int n) {
    srand(time(NULL));
    int* tab = new int[n];
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % 100;
    }
    return tab;
}

void wyswietlTablice(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int** stworzTablice2D(int w, int k){
    int** tab;
    srand(time(NULL));
    tab=new int*[w];
    for(int i=0; i<w; i++){
        tab[i]=new int[k];
        for(int j=0; j<k; j++) {
            tab[i][j]=rand()%100;
        }
    }
    return tab;
}

void wyswietl2D(int** tab, int w, int k) {
    cout << "2D: " << endl;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}


void sortowanieBabelkowe (int* tab, int n, int tryb) {
    switch (tryb) {
        case 1:
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n-i; j++) {
                    if (tab[j] > tab[j+1]) {
                        swap(tab[j], tab[j+1]);
                    }
                }
            }
            break;
        case -1:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n-i; j++) {
                    if (tab[j] < tab[j+1]) {
                        swap(tab[j], tab[j+1]);
                    }
                }
            }
        break;
        default:
            cout << "Tryby:" << endl<<"1 - rosnacy"<<endl << "-1 - malejacy"<< endl;
        break;
    }

}

void sortowaniePrzezWybor(int* tab, int n, int tryb) {
    switch (tryb) {
        case 1:
            for (int i = 0; i <= n; i++) {
                int min = tab[i];
                int minIdx = i;
                for (int j = i; j <= n; j++) {
                    if (tab[j] < min) {
                        min = tab[j];
                        minIdx = j;
                    }

                }
                swap(tab[i], tab[minIdx]);
            }
        break;
        case -1:
            for (int i = 0; i < n; i++) {
                int max = tab[i];
                int maxIdx = i;
                for (int j = i; j <= n; j++) {
                    if (tab[j] > max) {
                        max = tab[j];
                        maxIdx = j;
                    }

                }
                swap(tab[i], tab[maxIdx]);
            }
        break;
        default:
            cout << "Tryby:" << endl<<"1 - rosnacy"<<endl << "-1 - malejacy"<< endl;
        break;
    }
}

void sortowaniePrzezWstawianie(int* tab, int n, int tryb) {
    int* arr = new int[n];
    switch (tryb) {
        case 1:
            arr[0] = tab[0];
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    if (tab[i] < arr[j]) {
                        swap(tab[i], tab[j]);
                    }
                    cout << tab[i] << " ";
                }
                cout << endl;
            }
        break;

        case -1:
        arr[0] = tab[0];
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (tab[i] > arr[j]) {
                    swap(tab[i], tab[j]);
                }
                cout << tab[i] << " ";
            }
            cout << endl;
        }
        break;

    }
}

void sortowanieBabelkowe2D(int** tab, int w, int k, int tryb, int nrKol) {
    switch (tryb) {
        case 1:
            for (int i = 0; i < w; i++) {
                for (int j = 0; j < w-i; j++) {
                    if (tab[j][nrKol] < tab[j+1][nrKol]) {
                        swap(tab[i], tab[i+1]);
                    }
                }
            }
        break;
        case -1:
            for (int i = 0; i < w; i++) {
                for (int j = 0; j < w-i; j++) {
                    if (tab[j][nrKol] > tab[j+1][nrKol]) {
                        swap(tab[i], tab[i+1]);
                    }
                }
            }
            break;
    }


}


int main() {
    int n = 3;
    int* tab = stworzTablice(n);
    int wybor, tryb;
    cout << "1) zadanie 2.2" << endl;
    cout << "2) zadanie 2.3" << endl;
    cout << "3) zadanie 2.4" << endl;
    cout << "4) zadanie 2.5" << endl;
    cin >> wybor;
    cout << " 1 - rosnaco" << endl;
    cout << "-1 - malejaco" << endl;
    cin >> tryb;

    switch (wybor) {
        case 1:
            sortowaniePrzezWybor(tab, n, tryb);
        break;
        case 2:
            sortowaniePrzezWybor(tab, n, tryb);
        break;
        case 3:
            sortowaniePrzezWstawianie(tab, n, tryb);
        break;
        case 4:
            int** tab2d = stworzTablice2D( n, n);
            wyswietl2D(tab2d, n, n);
            sortowanieBabelkowe2D(tab2d, n, n, tryb, 1);
            wyswietl2D(tab2d, n, n);
        break;
        
    }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.