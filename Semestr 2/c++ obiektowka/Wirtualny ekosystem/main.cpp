#include <iostream>
#include "Ecosystem.h"
#include "InputReader.h"
#include "Organisms/Algae.h"
#include "Organisms/Fungi.h"
#include "Organisms/Bacteria.h"

using namespace std;

int main() {
    srand(time(NULL));
    InputReader input_reader("start.txt", "output.txt");
    input_reader.readInput();

    Ecosystem game_board(input_reader.readInput());
    game_board.printBoard();

    vector<char> neighbours = game_board.getNeighbours(3, 3);
    cout << "Neighbors: ";
    for (char n : neighbours) {
        cout << n << " ";
    }
    cout << endl;

    // Pass config to Fungi
    Fungi grzyb;
    grzyb.show();
    grzyb.eat();

    Algae glon;
    glon.show();
    glon.eat();

    Bacteria bakteria;
    bakteria.show();
    bakteria.eat();

    return 0;
}
