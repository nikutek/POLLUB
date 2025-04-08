#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Ecosystem.h"
#include "IO.h"
#include "UI.h"
#include "Organisms/Algae.h"
#include "Organisms/Fungi.h"
#include "Organisms/Bacteria.h"
#include "Organisms/Empty.h"

using namespace std;

int main() {
    srand(time(NULL));

    vector<vector<Organism *> > initialBoard = IO::readInput("start.txt");
    Ecosystem game_board(initialBoard);


    UI ui;
    ui.start(200);


    return 0;
}
