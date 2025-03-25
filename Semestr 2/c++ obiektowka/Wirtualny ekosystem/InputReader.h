//
// Created by user on 24-Mar-25.
//

#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <iostream>
#include <vector>
using namespace std;

class InputReader{
    private:
    string inputFileName;
    string outputFileName;


    public:
    InputReader(string inputFileName, string outputFileName);

    vector<vector<char>> readInput();

    string getInputFileName();

    string getOutputFileName();



};

#endif //INPUTREADER_H
