#include "Ecosystem.h"

#include <iostream>
#include <ostream>

Ecosystem::Ecosystem(vector<vector<char>> startingPosition) {
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
    for (vector<char> row : this->board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

vector<char> Ecosystem::getNeighbours(int x, int y) {
    if (x < 0 || x >= this->width || y < 0 || y >= this->height) {
        cout << "Invalid Position (" << x << ", " << y << ")" << endl;
        return vector<char>();
    }

    vector<char> neighbours;

    // Loop through all possible neighbor positions (-1,0,+1 offsets)
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; // Skip the cell itself

            int newX = x + dx;
            int newY = y + dy;

            // Check if the new position is inside the board boundaries
            if (newX >= 0 && newX < this->width && newY >= 0 && newY < this->height) {
                neighbours.push_back(this->board[newY][newX]);
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


