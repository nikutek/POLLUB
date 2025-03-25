//
// Created by user on 24-Mar-25.
//

#ifndef INPUTREADER_H
#define INPUTREADER_H
#include <iostream>

using namespace std;

class InputReader {
private:
    string inputFileName;
    string outputFileName;

public:
    InputReader(string inputFileName, string outputFileName);

    InputReader(string &inputFileName, string &outputFileName);

    void readInput();

    string getInputFileName();

    string getOutputFileName();

    ~InputReader();
};


#endif //INPUTREADER_H
