//
// Created by user on 24-Mar-25.
//

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <string>
#include <vector>
using namespace std;

class Ecosystem {
private:
    vector<vector<char> > board;
    int generation;
    int width;
    int height;

public:
    Ecosystem(vector<vector<char> > startingPosition);

    void printBoard();

    int getWidth();

    int getHeight();

    vector<char> getNeighbours(int x, int y);

    // ~GameBoard();
};


#endif //GAMEBOARD_H
