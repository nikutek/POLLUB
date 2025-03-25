//
// Created by user on 24-Mar-25.
//

#include "InputReader.h"

#include <fstream>
#include <sstream>


InputReader::InputReader(string &inputFileName, string &outputFileName) {
    this->inputFileName = inputFileName;
    this->outputFileName = outputFileName;
}

void InputReader::readInput() {
string linia, temp;
    ifstream plik;
    int liczbaWierszy;
    stringstream ss;

    plik.open(this->inputFileName);
    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku " << this->inputFileName << endl;
        // return;
    }

    plik >> liczbaWierszy;
    while (getline(plik, temp)) {
        ss.clear();
        ss.str(temp);
        getline(plik, linia);
        liczbaWierszy--;
    }
    plik.close();

}


string InputReader::getInputFileName() {
    return this->inputFileName;
}

string InputReader::getOutputFileName() {
    return outputFileName;
}

InputReader::~InputReader() {}


