//
// Created by user on 29-Mar-25.
//

#ifndef UI_H
#define UI_H

#include <iostream>

#include "Organisms/Organism.h"


class UI {
public:
    static void start(int turns);

    static void printBoard(vector<vector<Organism *> > board);

    static void printStatistics(vector<vector<Organism *> > board);
};


#endif //UI_H
