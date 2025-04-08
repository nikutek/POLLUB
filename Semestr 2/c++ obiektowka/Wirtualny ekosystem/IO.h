#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <iostream>
#include <vector>
#include "Organisms/Organism.h"
using namespace std;

class IO {
public:
    static vector<vector<Organism *> > readInput(const string &inputFileName);

    static void writeOutput(const vector<vector<Organism *> > &board, int turn, const string &outputFileName);
};

#endif //INPUTREADER_H
