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

    // Read input file and create ecosystem
    vector<vector<Organism*>> initialBoard = IO::readInput("start.txt");
    Ecosystem game_board(initialBoard);

    // Initialize UI and start simulation
    UI ui;
    ui.start(200);



    return 0;
}