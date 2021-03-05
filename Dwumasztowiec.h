#ifndef DWUMASZTOWIEC_H
#define DWUMASZTOWIEC_H

#include "Statek.h"
#include <iostream>
#include <cmath>

using namespace std;

class Dwumasztowiec : public Statek
{
public:
    int obrazenia;
    int *wspolrzedna;
    int wielkosc;
    Dwumasztowiec();
};
#endif
