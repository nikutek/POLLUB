//
// Created by user on 24-Mar-25.
//

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "Organisms/Organism.h"
#include <vector>
using namespace std;

class Ecosystem {
private:
    vector<vector<Organism*> > board;
    int generation;
    int width;
    int height;

public:
    Ecosystem(vector<vector<Organism*> > startingPosition);

    void printBoard();

    vector<vector<Organism*> > getBoard();

    int getWidth();

    int getHeight();

    vector<Organism*> getNeighbours(int x, int y);

    void moveOrganism(int x, int y);

    // ~GameBoard();
};


#endif //GAMEBOARD_H
