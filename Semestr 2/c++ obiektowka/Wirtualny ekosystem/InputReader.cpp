//
// Created by user on 24-Mar-25.
//

#include "InputReader.h"

#include <fstream>
#include <sstream>
#include <vector>



InputReader::InputReader(string inputFileName, string outputFileName) {
    this->inputFileName = inputFileName;
    this->outputFileName = outputFileName;
}

#include <fstream>
#include <sstream>
#include <vector>

vector<vector<char>> InputReader::readInput() {
    ifstream file(this->inputFileName);
    if (!file.is_open()) {
        cout << "Nie udało się otworzyć pliku " << this->inputFileName << endl;
        exit(EXIT_FAILURE);
    }

    if (file.fail()) {
        cout << "Błąd podczas wczytywania liczby wierszy!" << endl;
        exit(EXIT_FAILURE);
    }

    vector<string> lines;
    string line;
    vector<vector<char>> grid;

    while (getline(file, line)) {
        vector<char> row;
        for (char c : line) {
            if (c != ' ') {
                row.push_back(c);
            }
        }
        if (!row.empty()) {
            grid.push_back(row);
        }
    }
    file.close();
    return grid;
}



string InputReader::getInputFileName() {
    return this->inputFileName;
}

string InputReader::getOutputFileName() {
    return outputFileName;
}


