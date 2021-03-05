#ifndef TRZYMASZTOWIEC_H
#define TRZYMASZTOWIEC_H

#include "Statek.h"
#include <iostream>
#include <cmath>

using namespace std;

class Trzymasztowiec : public Statek
{
public:
    int obrazenia;
    int *wspolrzedna;
    int wielkosc;
    Trzymasztowiec();
};
#endif
