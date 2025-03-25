#include <iostream>

#include "Ecosystem.h"
#include "InputReader.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    InputReader input_reader("start.txt", "output.txt");
    input_reader.readInput();
    Ecosystem game_board(input_reader.readInput());
    game_board.printBoard();
    cout << std::to_string(game_board.getHeight()) << endl;
    cout << std::to_string(game_board.getWidth()) << endl;
    vector<char> neighbours = game_board.getNeighbours(3,3);
    cout << "sasiedzi: ";
    for (char n : neighbours) {
        cout << n << " ";
    }
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
