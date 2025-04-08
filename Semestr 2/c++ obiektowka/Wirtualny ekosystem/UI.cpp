#include "UI.h";

#include <chrono>
#include <thread>

#include "Organisms/Organism.h"
#include <vector>

#include "Ecosystem.h"
#include "IO.h"

using namespace std;

void UI::printBoard(vector<vector<Organism *> > board) {
    for (vector<Organism *> row: board) {
        for (Organism *organism: row) {
            cout << organism->getSymbol() << ' ';
        }
        cout << endl;
    }
}

void UI::start(int turns) {
    for (int i = 0; i <= turns; i++) {
        Ecosystem::simulateStep();
        cout << endl;
        UI::printBoard(Ecosystem::getBoard());
        cout << endl;
        cout << "Turn: " << i << endl;
        UI::printStatistics(Ecosystem::getBoard());
        cout << "----------------------------------------------------" << endl;
        IO::writeOutput(Ecosystem::getBoard(), i, "output.txt");
        // std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void UI::printStatistics(vector<vector<Organism *> > board) {
    int numberOfAlgae = 0;
    int numberOfBacteria = 0;
    int numberOfFungi = 0;
    int numberOfDead = 0;

    for (vector<Organism *> row: board) {
        for (Organism *org: row) {
            switch (org->getSymbol()) {
                case '#': numberOfAlgae++;
                    break;
                case '*': numberOfBacteria++;
                    break;
                case '@': numberOfFungi++;
                    break;
                case '+': numberOfDead++;
                    break;
            }
        }
    }

    cout << "Number of Algae: " << numberOfAlgae << endl;
    cout << "Number of Bacteria: " << numberOfBacteria << endl;
    cout << "Number of Fungi: " << numberOfFungi << endl;
    cout << "Number of Dead organisms: " << numberOfDead << endl;
}
