#ifndef ECOSYSTEM_H
#define ECOSYSTEM_H

#include "Organisms/Organism.h"
#include <vector>

using namespace std;

class Ecosystem {
private:
    static vector<vector<Organism *> > board;
    static int width;
    static int height;
    int generation;

public:
    Ecosystem(vector<vector<Organism *> > startingPosition);

    static void simulateStep();

    static vector<vector<Organism *> > getBoard();

    static Organism *get(int x, int y);

    static void set(int x, int y, Organism *organism);

    static int getWidth();

    static int getHeight();

    static vector<Organism *> getNeighbours(int x, int y);

    static void moveOrganism(int x, int y);
};

#endif // ECOSYSTEM_H
