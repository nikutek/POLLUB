//
// Created by user on 24-Mar-25.
//

#include "InputReader.h"
#include "Organisms/Organism.h"
#include <fstream>
#include <sstream>
#include <vector>

#include "Organisms/Algae.h"
#include "Organisms/Bacteria.h"
#include "Organisms/Empty.h"
#include "Organisms/Fungi.h"


InputReader::InputReader(string inputFileName, string outputFileName) {
    this->inputFileName = inputFileName;
    this->outputFileName = outputFileName;
}

vector<vector<Organism*>> InputReader::readInput() {
    ifstream file(this->inputFileName);
    if (!file.is_open()) {
        cout << "Nie udało się otworzyć pliku " << this->inputFileName << endl;
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





string InputReader::getInputFileName() {
    return this->inputFileName;
}

string InputReader::getOutputFileName() {
    return outputFileName;
}


