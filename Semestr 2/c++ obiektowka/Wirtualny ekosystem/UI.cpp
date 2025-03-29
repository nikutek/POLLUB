
#include "UI.h";

#include <chrono>
#include <thread>

#include "Organisms/Organism.h"
#include <vector>

#include "Ecosystem.h"

using namespace std;

void clearConsole() {
#ifdef _WIN32
    system("cls");  // Windows command to clear the console
#else
    system("clear");  // Linux/macOS command to clear the console
#endif
}

void UI::printBoard(vector<vector<Organism*>> board){
    for (vector<Organism *> row: board) {
        // Static variable
        for (Organism *organism: row) {
            cout << organism->getSymbol() << ' ';
        }
        cout << endl;
    }
  }

void UI::start(int turns) {
    for (int i=0; i<turns; i++) {
        clearConsole();

        Ecosystem::simulateStep();
        cout << endl;
        UI::printBoard(Ecosystem::getBoard());
        cout << endl;
        UI::printStatistics(Ecosystem::getBoard());
        cout <<"----------------------------------------------------" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
void UI::printStatistics(vector<vector<Organism*>> board) {
    int numberOfAlgae=0;
    int numberOfBacteria=0;
    int numberOfFungi=0;
    int numberOfDead=0;

    for (vector<Organism *> row: board) {
        for (Organism *org: row) {
            switch (org->getSymbol()) {
                case '#': numberOfAlgae++; break;
                case '*': numberOfBacteria++; break;
                case '@': numberOfFungi++; break;
                case '+': numberOfDead++; break;
            }
        }
    }

    cout << "Number of Algae: " << numberOfAlgae<<endl;
    cout << "Number of Bacteria: " << numberOfBacteria<<endl;
    cout << "Number of Fungi: " << numberOfFungi<<endl;
    cout << "Number of Dead organisms: " << numberOfDead<<endl;
}
