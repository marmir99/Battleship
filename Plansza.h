#ifndef PLANSZA_H
#define PLANSZA_H

#include <iostream>
#include <cmath>
#include "Jednomasztowiec.h"
#include "Dwumasztowiec.h"
#include "Trzymasztowiec.h"
#include "Czteromasztowiec.h"
#include "Pieciomasztowiec.h"


using namespace std;
class Plansza {
private:
    bool przyzwolenie;
    int aktualny_strzal;
public:
    char **tablica;
    Plansza();
    void set_przyzwolenie(bool p);
    bool get_przyzwolenie();
    void set_statek(int wspolrzedna);
    void wyswietl();
    int czy_mozna(int indeks, int indeks2);
    int strzelaj(Plansza p);
    int inkrementuj_obrazenia( Jednomasztowiec **tab_jednomasztowcow,
                               Dwumasztowiec **tab_dwumasztowcow,
                               Trzymasztowiec **tab_trzymasztowcow,
                               Czteromasztowiec **tab_czteromasztowcow,
                               Pieciomasztowiec **tab_pieciomasztowcow,
                               int numer_gracza );

    void ustaw_jednomasztowiec( Jednomasztowiec *j);
    void ustaw_dwumasztowiec(Dwumasztowiec *d);
    void ustaw_trzymasztowiec (Trzymasztowiec *t);
    void ustaw_czteromasztowiec (Czteromasztowiec *c);
    void ustaw_pieciomasztowiec (Pieciomasztowiec *p);
    void reset_planszy ();
};
#endif
