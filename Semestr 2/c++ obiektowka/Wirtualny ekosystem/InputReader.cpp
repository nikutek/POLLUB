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

    if (file.fail()) {
        cout << "Błąd podczas wczytywania pliku!" << endl;
        exit(EXIT_FAILURE);
    }

    vector<vector<Organism*>> result;
    string line;

    while (getline(file, line)) {
        vector<Organism*> row;
        for (char c : line) {
            if (c == ' ') continue; // Ignore spaces

            switch (c) {
                case '#': row.push_back(new Fungi()); break;
                case '*': row.push_back(new Algae()); break;
                case '@': row.push_back(new Bacteria()); break;
                default:  row.push_back(new Empty()); break;
            }
        }

        if (!row.empty()) {
            result.push_back(row);
        }
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


