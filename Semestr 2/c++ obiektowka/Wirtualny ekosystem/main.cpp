#include <iostream>
#include "Ecosystem.h"
#include "InputReader.h"
#include "UI.h"
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
    UI ui;

    ui.start(200);

    return 0;
}
