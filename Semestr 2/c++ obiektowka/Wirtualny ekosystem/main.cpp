#include <iostream>
#include "Ecosystem.h"
#include "InputReader.h"
#include "Organisms/Fungi.h"
#include "Config.h"

using namespace std;

int main() {
    InputReader input_reader("start.txt", "output.txt");
    input_reader.readInput();

    Ecosystem game_board(input_reader.readInput());
    game_board.printBoard();

    cout << "Board height: " << game_board.getHeight() << endl;
    cout << "Board width: " << game_board.getWidth() << endl;

    vector<char> neighbours = game_board.getNeighbours(3, 3);
    cout << "Neighbors: ";
    for (char n : neighbours) {
        cout << n << " ";
    }
    cout << endl;

    // Create a Config instance
    Config config;

    // Pass config to Fungi
    Fungi grzyb(config);
    cout << "Fungi created with max age: " << grzyb.getAge() << endl;

    return 0;
}
