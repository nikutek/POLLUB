#include <iostream>
#include "Ecosystem.h"
#include "InputReader.h"
#include "Organisms/Algae.h"
#include "Organisms/Fungi.h"
#include "Organisms/Bacteria.h"
#include "Organisms/Empty.h"

using namespace std;

int main() {
    srand(time(NULL));
    InputReader input_reader("start.txt", "output.txt");
    input_reader.readInput();

    Ecosystem game_board(input_reader.readInput());
    game_board.printBoard();

    cout << endl;

    // Pass config to Fungi



    // game_board.moveOrganism(9, 1);
    // game_board.printBoard();


    // game_board.get(11,3)->show();  //eating sandbox
    // for (int i = 0; i < 10; i++) {
    //     if (game_board.get(10,3)->ageGrow()) {
    //     }
    //
    // }

    game_board.printBoard();

    for (vector<Organism*> row : game_board.getBoard()) {
        for (Organism* org : row) {
            if (org->getSymbol()=='#') {
                cout <<"grzyb:"<<endl;
                org->move();
            }
        }
    }
    game_board.printBoard();




    // Algae glon;
    // glon.show();
    // glon.eat();
    //
    // Bacteria bakteria;
    // bakteria.show();
    // bakteria.eat();

    return 0;
}
