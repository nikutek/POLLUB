#include "Ecosystem.h"

#include <algorithm>

#include "Organisms/Organism.h"
#include <iostream>
#include <ostream>
#include <bits/ranges_algo.h>

#include "Organisms/Empty.h"

Ecosystem::Ecosystem(vector<vector<Organism*>> startingPosition) {
    this->board = startingPosition;
    this->generation = 0;
    if (!startingPosition.empty()) {
        this->height = startingPosition.size();
        this->width = startingPosition[0].size();
    } else {
        this->height = 0;
        this->width = 0;
    }

}

void Ecosystem::printBoard() {
    cout << "Generation: " << generation << endl;
    for (vector<Organism*> row : this->board) {
        for (Organism* organism : row) {
            cout << organism->getSymbol() << ' ';
        }
        cout << endl;
    }
}

vector<vector<Organism *> > Ecosystem::getBoard() {
    return this->board;
}


vector<Organism*> Ecosystem::getNeighbours(int x, int y) {
    if (x < 0 || x >= this->width || y < 0 || y >= this->height) {
        cout << "Invalid Position (" << x << ", " << y << ")" << endl;
        return vector<Organism*>();
    }

    vector<Organism*> neighbours;

    // Loop through all possible neighbor positions (-1,0,+1 offsets)
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; // Skip the cell itself

            int newX = x + dx;
            int newY = y + dy;

            // Check if the new position is inside the board boundaries
            if (newX >= 0 && newX < this->width && newY >= 0 && newY < this->height) {
                Organism* organism = this->board[newY][newX];
                neighbours.push_back(organism);
            }
        }
    }

    return neighbours;
}

void Ecosystem::moveOrganism(Organism* organism, int x, int y) {
    vector<Organism*> neighbours = this->getNeighbours(x, y);
    int possiblesqaures =0;
    for (Organism* organism : neighbours) {
        if (organism->getSymbol() == '_') {
            possiblesqaures++;
        }
    }
    if (possiblesqaures == 0) {
        return;
    }
    int newX, newY;

    while (true) {
        newX = (rand() % 3)-1;
        newY = (rand() % 3)-1;
        while (x+newX >= this->width || x+newX < 0) {
            newX = (rand() % 3)-1;
        }

        while (y+newY >= this->height || y+newY < 0) {
            newY = (rand() % 3)-1;
        }

        if (board[y+newY][x+newX]->getSymbol() == '_') {
            swap(board[y+newY][x+newX], board[y][x]);
            break;
        }
    }
}

int Ecosystem::getWidth() {

    return this->width ? this->width : 0;
}

int Ecosystem::getHeight() {
    return this->height;
}


