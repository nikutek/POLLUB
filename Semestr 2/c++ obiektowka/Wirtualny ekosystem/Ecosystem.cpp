#include "Ecosystem.h"
#include "Organisms/Organism.h"
#include <iostream>
#include <ostream>

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
                neighbours.push_back(this->board[newX][newY]);
            }
        }
    }

    return neighbours;
}

int Ecosystem::getWidth() {

    return this->width ? this->width : 0;
}

int Ecosystem::getHeight() {
    return this->height;
}


