#ifndef GAUSS_H
#define GAUSS_H

#include <vector>

using Macierz = std::vector<std::vector<double>>;

bool gaussPodstawowy(Macierz& macierz);

bool gaussKolumnowy(Macierz& macierz);

bool gaussWierszowy(Macierz& macierz);

#endif
