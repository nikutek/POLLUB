#include "IO.h"
#include "Organisms/Organism.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "Organisms/Algae.h"
#include "Organisms/Bacteria.h"
#include "Organisms/Empty.h"
#include "Organisms/Fungi.h"

vector<vector<Organism*>> IO::readInput(const string& inputFileName) {
    ifstream file(inputFileName);
    if (!file.is_open()) {
        cout << "Nie udało się otworzyć pliku " << inputFileName << endl;
        exit(EXIT_FAILURE);
    }

    vector<vector<Organism*>> result;
    string line;
    int y = 0; // Track row position

    while (getline(file, line)) {
        vector<Organism*> row;
        int x = 0; // Track column position

        for (char c : line) {
            if (c == ' ') continue; // Ignore spaces

            Organism* org = nullptr;
            switch (c) {
                case '#': org = new Fungi(); break;
                case '*': org = new Algae(); break;
                case '@': org = new Bacteria(); break;
                default:  org = new Empty(); break;
            }

            if (org) {
                org->setPosition(x, y); // Assign position
                row.push_back(org);
            }

            x++; // Move to next column
        }

        if (!row.empty()) {
            result.push_back(row);
        }

        y++; // Move to next row
    }

    file.close();
    return result;
}

void IO::writeOutput(const vector<vector<Organism*>>& board, int turn, const string& outputFileName) {
    ofstream file(outputFileName, ios::app); // Open in append mode to keep previous turns

    if (!file.is_open()) {
        cout << "Failed to open file: " << outputFileName << endl;
        exit(EXIT_FAILURE);
    }


    // Print the board to file
    for (const vector<Organism*>& row : board) {
        for (const Organism* organism : row) {
            file << organism->getSymbol() << ' ';
        }
        file << '\n';
    }

    file << "\nTurn: " << turn << '\n';

    // Count organism types
    int numberOfAlgae = 0;
    int numberOfBacteria = 0;
    int numberOfFungi = 0;
    int numberOfDead = 0;

    for (const vector<Organism*>& row : board) {
        for (const Organism* org : row) {
            switch (org->getSymbol()) {
                case '#': numberOfFungi++; break;
                case '*': numberOfAlgae++; break;
                case '@': numberOfBacteria++; break;
                case '+': numberOfDead++; break;
            }
        }
    }

    // Write statistics
    file << "Number of Algae: " << numberOfAlgae << '\n';
    file << "Number of Bacteria: " << numberOfBacteria << '\n';
    file << "Number of Fungi: " << numberOfFungi << '\n';
    file << "Number of Dead organisms: " << numberOfDead << '\n';

    file << "----------------------------------------------------\n\n";

    file.close();
}