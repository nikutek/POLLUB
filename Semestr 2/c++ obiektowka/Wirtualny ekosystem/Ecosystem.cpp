#include "Ecosystem.h"
#include "Organisms/Organism.h"
#include "Organisms/Empty.h"

#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random numbers
#include <vector>

using namespace std;

// **Define static variables**
vector<vector<Organism *> > Ecosystem::board;
int Ecosystem::width = 0;
int Ecosystem::height = 0;

Ecosystem::Ecosystem(vector<vector<Organism *> > startingPosition) {
    // Initialize static board only once (when the first instance is created)
    if (board.empty()) {
        board = startingPosition;
        if (!startingPosition.empty()) {
            height = startingPosition.size();
            width = startingPosition[0].size();
        } else {
            height = 0;
            width = 0;
        }
    }
    this->generation = 0;

    srand(time(0)); // Seed random generator
}

void Ecosystem::simulateStep() {
    vector<Organism *> organisms;
    for (vector<Organism *> row: board) {
        for (Organism *org: row) {
            if (org->getSymbol() != '_' && org->getSymbol() != '+') organisms.push_back(org);
        }
    }


    for (Organism *organism: organisms) {
        if (organism->getSymbol() != '*') {
            int action = rand() % 2;
            if (organism->getRandomNeighbourOfType('_')) {
                // jesli ma gdzie sie ruszyc to losuje, w przeciwnym razie je
                if (action == 1) {
                    organism->move();
                    continue;
                }
            }
        }

        organism->eat();
        organism->reproduce();
        organism->ageGrow();

    }
    printBoard();
}


void Ecosystem::printBoard() {
    cout << "---------------------------" << endl;
    for (vector<Organism *> row: board) {
        // Static variable
        for (Organism *organism: row) {
            cout << organism->getSymbol() << ' ';
        }
        cout << endl;
    }
}

vector<vector<Organism *> > Ecosystem::getBoard() {
    return board;
}

Organism *Ecosystem::get(int x, int y) {
    return board[y][x];
}

void Ecosystem::set(int x, int y, Organism *organism) {
    board[y][x] = organism;
}

vector<Organism *> Ecosystem::getNeighbours(int x, int y) {
    vector<Organism *> neighbours;
    if (x < 0 || x >= width || y < 0 || y >= height) {
        cout << "Invalid Position (" << x << ", " << y << ")" << endl;
        return neighbours;
    }

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;

            int newX = x + dx;
            int newY = y + dy;

            if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
                neighbours.push_back(board[newY][newX]);
            }
        }
    }

    return neighbours;
}

void Ecosystem::moveOrganism(int x, int y) {
    Organism *current = board[y][x];

    if (!current) return;

    vector<pair<int, int> > emptyCells;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;

            int newX = x + dx;
            int newY = y + dy;

            if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
                if (board[newY][newX]->getSymbol() == '_') {
                    emptyCells.push_back({newX, newY});
                }
            }
        }
    }

    if (emptyCells.empty()) return;

    int randIndex = rand() % emptyCells.size();
    int newX = emptyCells[randIndex].first;
    int newY = emptyCells[randIndex].second;

    current->setPosition(newX, newY);

    swap(board[y][x], board[newY][newX]);
}

int Ecosystem::getWidth() {
    return width;
}

int Ecosystem::getHeight() {
    return height;
}
