#ifndef PIECIOMASZTOWIEC_H
#define PIECIOMASZTOWIEC_H

#include "Statek.h"
#include <iostream>
#include <cmath>

using namespace std;

class Pieciomasztowiec : public Statek
{
public:
    int obrazenia;
    int *wspolrzedna;
    int wielkosc;
    Pieciomasztowiec();
};
#endif
