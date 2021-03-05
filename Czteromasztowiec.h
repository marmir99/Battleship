#ifndef CZTEROMASZTOWIEC_H
#define CZTEROMASZTOWIEC_H

#include "Statek.h"
#include <iostream>
#include <cmath>

using namespace std;

class Czteromasztowiec : public Statek
{
public:
    int obrazenia;
    int *wspolrzedna;
    int wielkosc;
    Czteromasztowiec();
};
#endif
