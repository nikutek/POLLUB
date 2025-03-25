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
    if (x < 0 || x >= this->width || y < 0 || y >= this->height){
        cout << "Invalid Position" << endl;
        return vector<char>();
    }
    vector<char> neighbours;
    if (x==0 and y==0) { //top-left
        neighbours.push_back(this->board[y][x+1]);
        neighbours.push_back(this->board[y+1][x]);
        neighbours.push_back(this->board[y+1][x+1]);
    } else if (x==0 and y==this->height-1) { //left-bottom
        neighbours.push_back(this->board[y][x+1]);
        neighbours.push_back(this->board[y-1][x+1]);
        neighbours.push_back(this->board[y-1][x]);
    } else if (x == this->width - 1 && y == 0) { // top-right
        neighbours.push_back(this->board[y+1][x]);
        neighbours.push_back(this->board[y][x-1]);
        neighbours.push_back(this->board[y+1][x-1]);
    } else if (x==this->width-1 and y==this->height-1) {//right-bottom
        neighbours.push_back(this->board[y][x-1]);
        neighbours.push_back(this->board[y-1][x-1]);
        neighbours.push_back(this->board[y-1][x]);
    } else {
        for (int xx=-1 ; xx<=1 ; xx++) {
            for (int yy=-1 ; yy<=1; yy++) {
                if (xx==0 and yy==0) continue;
                neighbours.push_back(this->board[y+yy][x+xx]);
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


