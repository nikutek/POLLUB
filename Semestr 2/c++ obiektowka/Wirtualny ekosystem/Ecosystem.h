#ifndef ECOSYSTEM_H
#define ECOSYSTEM_H

#include "Organisms/Organism.h"
#include <vector>

using namespace std;

class Ecosystem {
private:
    static vector<vector<Organism*>> board;  // Shared across all instances
    static int width;  // Shared width
    static int height; // Shared height
    int generation; // Still instance-specific

public:
    Ecosystem(vector<vector<Organism*>> startingPosition);

    void printBoard();

    static vector<vector<Organism*>> getBoard(); // Now static

    static Organism* get(int x, int y);  // Static so it can access static board

    static void set(int x, int y, Organism* organism); // Static to modify static board

    static int getWidth();  // Static getter

    static int getHeight(); // Static getter

    static vector<Organism*> getNeighbours(int x, int y); // Static

    static void moveOrganism(int x, int y);
};

#endif // ECOSYSTEM_H
