#ifndef JEDNOMASZTOWIEC_H
#define JEDNOMASZTOWIEC_H

#include "Statek.h"
#include <iostream>
#include <cmath>

using namespace std;

class Jednomasztowiec : public Statek
{
public:
    int obrazenia;
    int *wspolrzedna;
    int wielkosc;
    Jednomasztowiec();
};
#endif
